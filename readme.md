# Setup in VSCode

Install 'Microsoft C/C++ Extension' extension. This is for intellisense.

Run the startup script in the current directory, this will install all systemc dependencies..

```bash
./setupSystemC.sh
```

# Run a project

Go to the code directory and run the build script

Ex:

```bash
cd code
./build.sh sample_project
./build.sh examples/Buttons
```

### Inspiration

https://www.youtube.com/watch?v=rLBScPm_bis

https://singularitykchen.github.io/blog/2020/06/18/Tutorial-Build-SystemC/#heading-ubuntu-2004-lts


# Overleaf  git Sync

git remote add overleaf https://git.overleaf.com/63160a000b86793bb9e5ab9c
git pull overleaf master
git push overleaf master

