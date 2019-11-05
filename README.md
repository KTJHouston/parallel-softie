# Breeding the Softie (in Parallel)
Fall 2019 Parallel Semester Project

An _enterprising entrepreneur_ has concluded that the ideal opportunity for him to combine his love
of dogs with a vast fortune is to corner the market for a new breed of dog: the Softie.

## Characteristics of the Softie are as follows:
```
A. Length of Coat: 8 in. or longer
B. Coat Characteristics: Extremely soft (or softer), brown areas on white background, white paws, black tail
C. Tail Characteristics: Short (4 in. to 6 in.), points straight up
D. Weight Extremely large: 90 kg or heavier
E. Foot Characteristics: Paw print area in excess of 9 sq. in., fully webbed between toes
F. Disposition: Extremely mild tempered
```
Each of these characteristics has a range when viewed across all dogs:

A. Can be represented by eight bits in which 000000002 corresponds to a hairless dog, 111111112 corresponds to a hair length of 10.2 in., and 110010002 corresponds to 8 in.

B. Can be represented by six softness bits (in which 0000002 corresponds to the ultimate in softness), 0001112 is extremely soft, and 1111112 is the ultimate in stiffness; three background brightness bits, in which 0002 is bright and 1112 is dark; three background color bits, in which white is 0002 and brown is 0012 and all other colors are covered by the remaining size combinations; three foreground brightness bits (0002 is bright); three foreground color bits (0002 is white, 0012 is brown, 0102 is red, 0112 is yellow, 1112 is black, and the remaining bit patterns are other colors); one bit for paw color, in which 0 corresponds to white and 1 is “anything else”; one bit for tail color, in which 0 corresponds to “anything else” and 1 corresponds to black.

C. Can be represented by 10 bits, in which eight are related to tail length (000000002 corresponds to a tailless variety, and 111111112 corresponds to a tail-length of 25.5 in. or longer) and two denote tail appearance: 002 correspond to pointing straight up, 012 correspond to pointing horizontally, 102 corresponds to pointing straight down, and 112 corresponds to the highly undesirable curly tailed appearance.

D. Can be represented by 10 bits, in which the first seven correspond to a weight in kg and the second three correspond to a weight in increments of 1/8 kg. Thus, a weight characteristic of 00000101012 would be a weight of 538 kg.

E. Can be represented by 10 bits, seven bits of which correspond to pawprint area and three to the fraction of webbed. In this example, 0000002 corresponds to a pawprint area of 0.5 sq. in., 11111112 corresponds to a pawprint area of 13.2 sq. in., and 01000112 corresponds to a pawprint area of 4.0 sq. in. In the final three bits, 0002 corresponds to 1/8 webbed, and 1112
corresponds to fully webbed.

F. Can be represented by six bits, in which 000000 corresponds to the ultimate in mild-tempered disposition, 0001002 is extremly mild tempered, and 1111112 is “meaner than a junkyard dog” - the ultimate in non-mild-temperedness.

### Example

Thus, in total, one needs 64 bits to represent an individual dog in this population. One such dog might be
11001000 001011 000000 111001 01 1000000011 001101100 0100011 011 000100 whose characteristics are:
```
• [110010002]   8 in. coat
• [0010112]     Slightly more stiff than desirable
• [0000002]     Background color is bright white
• [1110012]     Foreground color is dark brown
• [012]         White paws and black tail
• [10000000112] 12.8 in. long, curly-tailed
• [0011011002]  13.5 kg weight
• [01000112]    4 sq. in. pawprint area
• [0112]        50 percent webbed
• [0001002]     Extremely mild tempered
```
In short, this dog has some desirable characteristics (its coat is pretty good, its paw size is find, and its temperament is fine) and some that are undesirable (coat is a little stiffer than the standard, the tail is curly, the dog is extremely small compared to the standard, and it will not be a good water dog as desired due to its less than fully webbed toes).

## The Situation

The entrepreneur is anxious to hedge his bets on this project and hired both you and a competitor to develop Softies. 

Your competitor has a **single large kennel complex** in which he plans to house **500** dogs.
You have opted for **five independent kennel locations each housing 100 dogs.** 

*To Start:* Both of you plan to visit animal shelters and take the first 500 nonspayed/neutered dots you find (i.e. you will start off the initial population with “random” characteristics). 

Both your competitor and you plan to *keep the population sizes constant* in your kennels while breeding successive generations of dogs. You both plan to have in each kennel location two of its parents in the current generation that best match the standard for the Softie breed. In addition, since a pair of parents may have multiple offspring in a given litter (corresponding to making multiple “cuts” and crossovers), both of you plan to give away (to your friends) the offspring that least conform to the standards for Softies, as needed, to keep your local populations constant.

The major difference between you two is that he has a single large population of while you have five independent kennel “subcontractors” each working with an isolated subpopulation.. He will simply produce n generations of offspring; your subcontractors each will produce five generations of offspring in isolation, and only then send their two most fit dogs to their neighbors (A sends one to B and one to E, B sends one to A and one to C, etc.), as in the island model.

## This program is designed as:

1. A single-processor genetic algorithm solution modeled after your competitor’s approach. It can be run with several random initial populations and computes the average number of generations it takes before 10 percent of the population (50 dogs) meets the standards for Softies.

2. A multiprocessor/multicomputer genetic algorithm solution modeled after your approach. As in in Part 1, run this with several random initial populations and compute the average number of generations it takes before a total of 50 dogs from your kennels meets the
standards for Softies.

Instructor Note: You will need to construct an evaluation function that incorporates all of these characteristics, such that a dog meeting the characteristics of the Softie standard will exhibit a greater fitness than one that does not.

## Run

As more of the project is developed, information for running and testing the program will be included.

## Built With

* [C++]
* [VSCode]

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

* **Kenzie Clarke** - *Software Developer* - [Linkedin](https://www.linkedin.com/in/kenzieclarke07/)
* **Kenny Houston** - *Software Developer* - [Linkedin]()

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thank you to our professor Dr. Michael Scherger at Texas Christian University for the project inspiration and guidance throughout the project.
