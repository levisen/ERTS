/**
 * \author Malthe Faurschou Tøttrup & Jakob Levisen
 * \date 19-10-2022
 */

/**
 * @ref https://refactoring.guru/design-patterns/state/cpp/example
 * 
 */

#pragma once
#include <iostream>

class Context;

int SimCount = 0;

class State{
    protected:
        Context *context_;

    public:
        
        virtual ~State(){}
        virtual void Restart(){}
        virtual void SelfTestFailed(){}
        virtual void Exit(){}
        virtual void SelfTestOk(){}
        virtual void Initialized(){}
        virtual void chMode(){}
        virtual void RunRealTime(){}
        virtual void Simulate(){}
        
        void set_context(Context *context) {
            this->context_ = context;
        }
};

class Context{
    protected:
        State *state_;

    public:
        explicit Context(State *state) : state_(nullptr){
            this->TransitionTo(state);
        }

        ~Context() {
            delete state_;
        }

        void TransitionTo(State *state) {
            std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
            if (this->state_ != nullptr)
                delete this->state_;
            this->state_ = state;
            this->state_->set_context(this);
        }

        void RequestRestart() {
            this->state_->Restart();
        }
        void RequestSelfTestFailed() {
            this->state_->SelfTestFailed();
        }
        void RequestExit() {
            this->state_->Exit();
        }
        void RequestSelfTestOk() {
            this->state_->SelfTestOk();
        }
        void RequestInitialized() {
            this->state_->Initialized();
        }
        virtual void RequestchMode() {}

        virtual void RequestRunRealTime() {}

        virtual void RequestSimulate() {}
};

class ApplicationModeSetting : public Context {

    using Context::Context;

    public:
        void RequestchMode() override;
};

class SimulateRealTimeState : public Context{

    using Context::Context;

    public:
        void RequestRunRealTime() override;
        
        void RequestSimulate() override;
};

void ApplicationModeSetting::RequestchMode() {
    this->state_->chMode();
}

void SimulateRealTimeState::RequestRunRealTime() {
    this->state_->RunRealTime();
}
void SimulateRealTimeState::RequestSimulate() {
    this->state_->Simulate();
}

class Failure : public State {
    public:
        void Exit() override;
        void Restart() override;
};

class Initializing : public State {

    void Initialized() override;
};

class Mode1 : public State {
    public:
        void chMode() override;
};

class Mode2 : public State {
    public:
        void chMode() override;
};

class Mode3 : public State {
    public:
        void chMode() override;
};

class PowerOnSelfTest : public State {
    public:
        void SelfTestFailed() override;
        void SelfTestOk() override;
};

class RealTimeExecution : public State {
    public:
        void Simulate() override;
};

class RealTimeLoop : public State {
    public:
        SimulateRealTimeState *SRTS;
        ApplicationModeSetting *AMS;
        
    RealTimeLoop(){
        SRTS = new SimulateRealTimeState( new RealTimeExecution);
        AMS = new ApplicationModeSetting( new Mode1);
        SRTS->RequestSimulate();
        AMS->RequestchMode();
    }

    void Restart() override;
};

class Simulation : public State {
    public:
        void RunRealTime() override;

};

// ----------------------

void Failure::Exit() {
    std::cout << "exiting" << std::endl;
}
void Failure::Restart() {
    this->context_->TransitionTo(new PowerOnSelfTest);
}

void Initializing::Initialized() {
    this->context_->TransitionTo(new RealTimeLoop);
}

void Mode1::chMode() {
    this->context_->TransitionTo(new Mode2);
}
void Mode2::chMode() {
    this->context_->TransitionTo(new Mode3);
}
void Mode3::chMode() {
    this->context_->TransitionTo(new Mode1);
}

void PowerOnSelfTest::SelfTestFailed() {
    this->context_->TransitionTo(new Failure);
}
void PowerOnSelfTest::SelfTestOk() {
    this->context_->TransitionTo(new Initializing);
}

void RealTimeExecution::Simulate() {
    SimCount++;
    std::cout << "SimCount: " << SimCount << std::endl;
    this->context_->TransitionTo(new Simulation);
}

void RealTimeLoop::Restart() {
    delete SRTS;
    delete AMS;
    this->context_->TransitionTo(new PowerOnSelfTest);
}

void Simulation::RunRealTime() {
    this->context_->TransitionTo(new RealTimeExecution);
}

