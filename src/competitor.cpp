/**********
 * Sequential Genetic Algorithmn in psuedocode from the Book scan
 * 
 * ***start***
 * generation_num = 0;
 * initialize Population(generation_num);
 * evaluate Population(generation_num);
 * set termaination_condition to False;
 * while(not termination_condition) {
 *      generation_num++;
 *      select Parents from Population(generation_num - 1);
 *      apply crossover to Parents(generation_num) to get Offspring(generation_num);
 *      apply mutation to Offspring(generation_num) to get Population(generation_num);
 *      evaluate Population(generation_num) and update termination_condition;
 * }
 * ***end***
 * 
 * This is the design for the competitor's dog breeding - run on one kernel = sequential
 * ****/

//Dependencies
#include "DNA.h"
#include <vector>

using namespace std;

//Methods
int eval_p(vector<DNA> generation, int generation_num);
vector<DNA> initial_p(int generation_num, int start);
vector<DNA> select_parents(int value);
vector<DNA> apply_crossover(vector<DNA> parents, int generation_num);
vector<DNA> apply_mutation(vector<DNA> offspring, int generation_num);

void print_initial_stats(vector<DNA> generation, int generation_num, int goal_achieved);
void print_generation(vector<DNA> parents, vector<DNA> offspring, vector<DNA> generation, int goal_achieved);
void print_final_stats(int goal_achieved, vector<DNA> generation);
/***
 * main method
 * 
 * contains the sequential breeding simulation of our softie competitor
 * 
 * starting with an initial population of 500 dogs, the competitor goes
 * through a cycle of generations untill he successfully breeds at least
 * 50 softies (10% of the total population)
 * 
 * each generation, the breeder selects the most 'fit' dogs by softie 
 * characteristics, applies the crossover genes to their offspring. From
 * there, a small portion of the offspring recieve genetic mutations. At the
 * end of the generation, he checks to see if he has enough softies (50 or more).
 * 
 * ***/
int main(){

    int generation_num = 0;
    //randomly generate the initial population of size 500
    vector<DNA> generation = initial_p(generation_num, 500);
    //check for the number of viable 'softies'
    /*
    int goal_achieved = eval_p(generation, generation_num);
    print_initial_stats(generation, generation_num, goal_achieved);

    while(goal_achieved < 50){
        generation_num++;
        vector<DNA> parents = select_parents(generation_num - 1);
        //DEV_NOTE: apply_crossover plans to 'give away' the least fit dogs to maintain population numbers
        vector<DNA> offspring = apply_crossover(parents, generation_num);
        //DEV_NOTE: apply_mutation affects only a portion of the offspring
        generation = apply_mutation(offspring, generation_num);             
        goal_achieved = eval_p(generation, generation_num);
        print_generation(parents, offspring, generation, goal_achieved);
    }

    print_final_stats(goal_achieved, generation);
    */
    while(!generation.empty()){
        DNA dog = generation.back();
        cout << "Dog # " << generation.size() << ": " << dog.to_string << endl;
        generation.pop_back();
    }
    return 0;
}
