#include "population_clustered.h"
#include <QDebug>

//Constructor
Population_clustered::Population_clustered(int number_generation, int number_individual,int number_cluster) :
_number_generation(number_generation),
_number_individual(number_individual),
_number_cluster(number_cluster),
_generations(std::vector<Generation_clustered>(number_generation, Generation_clustered(number_individual,number_cluster)))
{

}

Population_clustered::Population_clustered(const Population_clustered& pop)
{
    _generations = pop.get_generation() ;
    _number_generation = pop.get_number_generation() ;
    _number_individual = pop.get_number_individuals() ;
    _number_cluster = pop.get_number_cluster() ;
    _number_crossover = pop.get_number_crossover() ;
    _number_mutation = pop.get_number_mutation() ;
}

//Destructor
Population_clustered::~Population_clustered()
{
    _generations.clear();
}

//Getter
int Population_clustered::get_number_generation() const
{
    return _number_generation;
}

int Population_clustered::get_number_individuals() const
{
    return _number_individual;
}

int Population_clustered::get_number_cluster() const
{
    return _number_cluster;
}

int Population_clustered::get_number_crossover() const
{
    return _number_crossover ;
}

int Population_clustered::get_number_mutation() const
{
    return _number_mutation ;
}

std::vector<Generation_clustered> Population_clustered::get_generation() const
{
    return _generations ;
}

double Population_clustered::get_best_score() const
{
    return _best_score ;
}

double Population_clustered::get_worst_score() const
{
    return _worst_score ;
}

//Setter
void Population_clustered::set_number_crossover(int number_crossover)
{
    _number_crossover = number_crossover ;
}

void Population_clustered::set_number_mutation(int number_mutation)
{
    //qDebug() << number_mutation ;
    _number_mutation = number_mutation ;
}

void Population_clustered::set_best_score(double best_score)
{
    _best_score = best_score ;
}

void Population_clustered::set_worst_score(double worst_score)
{
    _worst_score = worst_score ;
}

//Operator
Generation_clustered & Population_clustered::operator [] (int i)
{
    if (i < 0)
    {
        throw("ERROR - Population::operator [] : INDEX OUT OF RANGE");
    }
    else if(i>=_generations.size())
    {
        throw("ERROR - Population::operator [] : INDEX OUT OF RANGE");
    }
    return _generations[i];
}

Generation_clustered Population_clustered::operator [] (int i) const
{
    if (i < 0)
    {
        throw("ERROR - population.cpp - Population::operator [] : INDEX OUT OF RANGE");
    }
    else if (i >= _generations.size())
    {
        throw("ERROR - population.cpp - Population::operator [] : INDEX OUT OF RANGE");
    }
    return _generations[i];
}

std::ostream& operator<<(std::ostream& os, const Population_clustered& population)
{
    for (int i = 0; i < population.get_number_generation(); i++)
    {
        for (int j = 0; j < population.get_number_cluster(); j++)
        {
            for(int k=0;k < population.get_number_individuals();k++)
            {
                os << population[i][j][k] << "\n";
            }
        }
    }
    return os;
}

