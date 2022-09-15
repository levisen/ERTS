#ifndef TOP_H
#define TOP_H
#include <systemc.h>
#include "stimulus.h"
#include "mac.h"
#include "monitor.h"

SC_MODULE(Top) {
    sc_signal<int> siga, sigb, sigc, sigf;
    sc_clock clock;

    Stimulus *stim;
    Mac *mac;
    Monitor *mon;

    SC_CTOR(Top): clock("clock", sc_time(20, SC_NS))
    {   
        stim = new Stimulus("stim");
        mac = new Mac("mac");
        mon = new Monitor("mon");
        stim->a(siga);
        stim->b(sigb);
        stim->c(sigc);
        stim->clk(clock);

        mac->a(siga);
        mac->b(sigb);
        mac->c(sigc);
        mac->f(sigf);

        mon->f(sigf);
        mon->clk(clock);
    }
};
#endif
