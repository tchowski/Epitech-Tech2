/*
** EPITECH PROJECT, 2019
** Kitchen.cpp
** File description:
** Kitchen
*/

#include "Americana.hpp"
#include "Fantasia.hpp"
#include "Margarita.hpp"
#include "Reception.hpp"
#include "Regina.hpp"
#include <pthread.h>
#include <sstream>
#include <string>
#include <thread>

// crée fonction qui trie les pizzas
pthread_cond_t condition = PTHREAD_COND_INITIALIZER; /* Création de la condition */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; /* Création du mutex */

APizza *Kitchen::MakePizza(APizza::PizzaType &pizzaType, APizza::PizzaSize &pizzaSize)
{
    if (pizzaType == APizza::PizzaType::Regina)
        return (new Regina(pizzaSize));
    if (pizzaType == APizza::PizzaType::Margarita)
        return (new Margarita(pizzaSize));
    if (pizzaType == APizza::PizzaType::Fantasia)
        return (new Fantasia(pizzaSize));
    if (pizzaType == APizza::PizzaType::Americana)
        return (new Americana(pizzaSize));
    return nullptr;
}

void Kitchen::decIngredient(APizza &pizza)
{
    std::vector<std::string> ing = pizza.getIngredients();
    int i = 0;

    for (auto it = ing.begin(); it != ing.end(); it++, i++) {
        if (strcmp(ing[i].c_str(), "doe") == 0)
            _ingredients["doe"] -= 1;
        if (strcmp(ing[i].c_str(), "tomato") == 0)
            _ingredients["tomato"] -= 1;
        if (strcmp(ing[i].c_str(), "gruyere") == 0)
            _ingredients["gruyere"] -= 1;
        if (strcmp(ing[i].c_str(), "ham") == 0)
            _ingredients["ham"] -= 1;
        if (strcmp(ing[i].c_str(), "mushrooms") == 0)
            _ingredients["mushrooms"] -= 1;
        if (strcmp(ing[i].c_str(), "steak") == 0)
            _ingredients["steak"] -= 1;
        if (strcmp(ing[i].c_str(), "eggplant") == 0)
            _ingredients["eggplant"] -= 1;
        if (strcmp(ing[i].c_str(), "goat cheese") == 0)
            _ingredients["goat cheese"] -= 1;
        if (strcmp(ing[i].c_str(), "chief love") == 0)
            _ingredients["chief love"] -= 1;
    }
}

void *Kitchen::cookPizza()
{
    _mutex = new Mutex();
    _condition = new ConditionVariableMutex();
    Margarita *margarita = new Margarita(APizza::PizzaSize::S); /* Trouver un moyen d'ajouter une pizza par son type */
    std::cout << "Temp de cuisson pour la pizza sans multiplier: " << margarita->getCookingTime() << std::endl;
    int nombre_pizza = 3; /* A remplacer par le nombre réel de pizza */

    /* nombre de pizza */
    while (nombre_pizza != 0) {
        std::cout << "Start Thread" << std::endl;
        sleep(margarita->getCookingTime() * this->_multiplier); /* Temps de cuisson */
        _mutex->lock_mutex(); /* On verrouille le mutex */
        _condition->cond_signal(); /* On délivre le signal : condition remplie */
        _mutex->unlock_mutex(); /* On déverrouille le mutex */
        nombre_pizza--;
    }
    std::cout << "End Thread" << std::endl;
    pthread_exit(NULL); /* Fin du thread */
}

void *Kitchen::ingredient()
{
    while (1) {
        _mutex->lock_mutex(); /* On verrouille le mutex */
        _condition->cond_wait(_mutex->getMutex()); /* On attend que la condition soit remplie */
        printf("La pizza est prête\n");
        _mutex->unlock_mutex(); /* On déverrouille le mutex */
    }
    pthread_exit(NULL); /* Fin du thread */
}

/* Threads */

void *static_cook_pizza(void *f)
{
    reinterpret_cast<Kitchen *>(f)->cookPizza();
    return (NULL);
}

void *static_ingredient(void *f)
{
    reinterpret_cast<Kitchen *>(f)->ingredient();
    return (NULL);
}

void Kitchen::startThread()
{
    int nombre_threads;
    if (static_cast<unsigned int>(this->getNombreThreads()) < this->_command.size()) /* <- Reste à trier les pizza */
        nombre_threads = this->_command.size();
    else
        nombre_threads = this->getNombreThreads();
    std::cout << "Nombre de threads: " << nombre_threads << std::endl;

    /* Thread Pool Implémentation */
    // _cook = new ThreadPool(nombre_threads, &static_cook_pizza, (void *)this);
    // _ingredient = new ThreadPool(nombre_threads, &static_ingredient, (void *)this);

    // std::list<Thread *>::iterator it_cook;
    // std::list<Thread *>::iterator it_ingredient;
    // for (it_cook = _cook->_threadsPool.begin(); it_cook != _cook->_threadsPool.end(); ++it_cook) {
    //     (*it_cook)->Start();
    //     (*it_ingredient)->Start();
    //     (*it_cook)->Wait();
    //     (*it_ingredient)->Wait();
    // }

    /*
    **
    */

    Thread *cook = new Thread(&static_cook_pizza, (void *)this);
    Thread *ingredient = new Thread(&static_ingredient, (void *)this);
    cook->Start();
    ingredient->Start();
    cook->Wait();
    ingredient->Wait();

    // std::thread th[nombre_threads];
    // std::thread th2[nombre_threads];
    // for (int i = 0; i < nombre_threads; ++i) {
    //     printf("id: %d\n", i);
    //     th[i] = std::thread(&Kitchen::cookPizza, this);
    //     th2[i] = std::thread(&Kitchen::ingredient, this);
    //     th[i].join();
    //     th2[i].join();
    // }

    std::cout << "Fin des Threads " << std::endl;
}

std::vector<std::string> Kitchen::StingToVector(std::string _command)
{
    std::stringstream ss(_command);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    return vstrings;
}

std::vector<std::string> Kitchen::Split(const std::string &str, int splitLength)
{
    int NumSubstrings = str.length() / splitLength;
    std::vector<std::string> ret;

    for (auto i = 0; i < NumSubstrings; i++) {
        ret.push_back(str.substr(i * splitLength, splitLength));
    }
    if (str.length() % splitLength != 0) {
        ret.push_back(str.substr(splitLength * NumSubstrings));
    }

    Utils util;
    util.print_vector(ret);
    return ret;
}

void Kitchen::setIngredients()
{
    _ingredients["doe"] = 5;
    _ingredients["tomato"] = 5;
    _ingredients["gruyere"] = 5;
    _ingredients["ham"] = 5;
    _ingredients["mushrooms"] = 5;
    _ingredients["steak"] = 5;
    _ingredients["eggplant"] = 5;
    _ingredients["goat cheese"] = 5;
    _ingredients["chief love"] = 5;
}

Kitchen::Kitchen(std::string command, float multiplier, int nombreCuisinier, int time)
    : _multiplier(multiplier)
    , _nombreCuisinier(nombreCuisinier)
    , _recepiesResetTime(time)
{
    std::cout << "Welcome on board!" << std::endl;
    _command = this->StingToVector(command);
    std::cout << "Les pizza vont mettre: " << _multiplier << " secondes de plus." << std::endl;
    std::cout << "Les pizza sont: " << std::endl;
    utils->print_vector(_command);
    setIngredients();
    this->startThread();
}

Kitchen::~Kitchen()
{
}

void Kitchen::kitchenNumbers()
{
}

void Kitchen::startCooking()
{
}

// std::string Kitchen::getCommand() const
// {
//     return this->_command;
// }

int Kitchen::getNombreThreads() const
{
    return this->_nombreCuisinier;
}