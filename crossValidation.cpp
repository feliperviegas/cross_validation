#include "crossValidation.h"
using namespace std;
void  shuffle(std::vector<std::string> &a) {
    int idx = a.size(); //se eu não colocar esse -1 da falha se segmentação
    while (idx > 0) {
        int rnd_idx = (int)Utils::random(0.0, (double)idx);
        idx--;
        //    std::cout<<"idx "<<idx<<" rnd_idx "<<rnd_idx<<std::endl;
        std::string tmp = a[idx];
        a[idx] = a[rnd_idx];
        a[rnd_idx] = tmp;
    }
}

void read_input(const char* filename, std::vector<std::string> &vetor){
    std::ifstream file(filename);
    std::string lines;
    while(std::getline(file, lines)){
        vetor.push_back(lines);
    }
}

void gera_folds(std::vector<std::string> &vetor, int numFolds){
    int lines = static_cast<int>(static_cast<double>(vetor.size()) / numFolds);
    vector<ofstream*> fileFolds (numFolds);
    for(int i = 0; i < numFolds; i++){
        stringstream ss;
        ss << i;
        const string str = "dados" + ss.str() + ".dat";
        fileFolds[i] = new ofstream(str.c_str());
    }

    int aux = 0, i = 0;
    while(i < (lines*numFolds)){
        for(int j = 0; j < lines; j++){
            (*fileFolds[aux]) << vetor[i] << endl;
            ++i;
        }
        ++aux;
    }

    aux=0;
    for(; i < vetor.size(); i ++){
        (*fileFolds[aux]) << vetor[i] << endl;
        ++aux;
    }
    
    for(int i = 0; i < numFolds; i++){
        (*fileFolds[i]).close();
    }
}


int main(int argc, char** argv) {
    
    int numFolds = 10;
    char *dataFile = NULL;
    int seed = time(NULL);
    int iterator =1;
    int opt;
    
    while ((opt = getopt (argc, argv, "d:p:i:")) != -1) {
        switch (opt) {
            case 'd': dataFile = optarg; break;
            case 'p': numFolds = atoi(optarg); break;		//Porcentagem para teste
            case 'i': iterator = atoi(optarg); break;
            case '?':
                if (optopt == 'd')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                std::cerr << "USAGE: " << argv[0] << " -l <val> -i <val>" << std::endl;
                abort ();
        }
    }
    //seed = seed + iterator;
    srand48(iterator); 
    std::vector<std::string> vet;
    read_input(dataFile, vet);
    shuffle(vet);
    gera_folds(vet, numFolds);
    return 0;
}
