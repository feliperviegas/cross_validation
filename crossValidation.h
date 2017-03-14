#include <vector>
#include <utility>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "utils.hpp"

std::vector<std::string> vet;

void shuffle(std::vector<std::string> &a);

void read_input(const char* filename, std::vector<std::string> &vetor);

void gera_folds(std::vector<std::string> &vetor, int numFolds);
