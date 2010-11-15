#ifndef IMAGE
#define IMAGE
#include <string>
class Image{
	private:
    	std::string filename;
    public:
    	Image(std::string file){
    		filename=file;
		}
		std::string getFilename(){
			return filename;
		}
};
#endif
