#include <string>
#include <vector>

namespace num {
    static int _size_of_input;
    
    class num {
        private:
        


        public:

        // Convert string to array of interger
        static std::vector<int> _convert_in_array(std::string& __input);


        // for adding 
        static std::string add(std::string& __num1, std::string& __num2);


        // for substracting 
        static std::string substract(std::string& __num1, std::string& __num2);
        
    };
}