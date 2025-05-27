#include <fstream>
#include <sstream>
#include <vector>

class Reader
{
  public:

    static std::vector<std::vector<int>> loadData(std::string filename){
      std::ifstream fichier(filename);
      if (!fichier.is_open()){
        std::cout << "Le fichier n'a pas pu etre ouvert" <<std::endl;
        exit(EXIT_FAILURE);
      }
      //le fichier a ete lu
      std::vector<std::vector<int>> data;
      std::vector<int> ligne;
      std::string l,w;
      while (getline(fichier,l)){
        ligne.clear();
        std::stringstream ss(l);
        char delimiteur = *";";
        while (getline(ss, w, delimiteur)) {
				ligne.push_back(std::stoi(w));
			  }
			  data.push_back(ligne);
      }
      fichier.close();
      return data;
    }

    static std::vector<std::vector<int>> getData()
    {
        return std::vector<std::vector<int>>{
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 1}, {1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    }
};