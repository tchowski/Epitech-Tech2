/*
** EPITECH PROJECT, 2019
** Core
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::string libPath)
    : Arcade(libPath)
{
    GetLibraryPath();
    Opendl(_currentLib);
    _currentLib.erase(0, 6);
}

void Core::GameLoop()
{
    IGfx *lib;
    IGfx::ACTION COMMANDE;
    lib = setSymdl();
    lib->createWindow();
    lib->gfxLoop(COMMANDE);

    while (isOpen) {
        if (COMMANDE == IGfx::ACTION::PREV_GFX) {
            destroyClass(lib);
            _currentLib = Libs.at(PreviousLib(Libs));
            AddCompletePath(_currentLib);
            Opendl(_currentLib);
            lib = setSymdl();
            lib->createWindow();
            lib->gfxLoop(COMMANDE);
            _currentLib.erase(0, 6);
        }
        if (COMMANDE == IGfx::ACTION::NEXT_GFX) {
            destroyClass(lib);
            _currentLib = Libs.at(NextLib(Libs));
            AddCompletePath(_currentLib);
            Opendl(_currentLib);
            lib = setSymdl();
            lib->createWindow();
            lib->gfxLoop(COMMANDE);
            _currentLib.erase(0, 6);
        }
        if (COMMANDE == IGfx::ACTION::OTHER)
            exit(0);
    }
}

void Core::Opendl(const std::string libPath)
{
    this->_handler = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!this->_handler) {
        fputs(dlerror(), stderr);
        exit(84);
    }
}

IGfx *Core::setSymdl()
{
    char *error;

    create_t *libGraphic = (create_t *)dlsym(this->_handler, "create");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(84);
    }
    IGfx *lib = libGraphic();
    return lib;
}

void Core::destroyClass(IGfx *lib)
{
    const char *dlsym_error;

    destroy_t *destroy_class = (destroy_t *)dlsym(this->_handler, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
    destroy_class(lib);
    closeLib();
}

void Core::closeLib()
{
    dlclose(this->_handler);
}