#include "GL/glu.h"
#include <GL/gl.h>
#include "physicsLevel.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//create object for coordinates
struct coordinate{
	float x,y,z;
	coordinate(float a,float b,float c) : x(a),y(b),z(c) {};
};
float furthestYlP;
float largestRY[20];
float largestRX[20];
struct face{
	int facenum;
	bool four;
	int* facesP = (int *) malloc(4 * sizeof(int));
	face(int facen,int f1,int f2,int f3) : facenum(facen){	//constructor for triangle
		facesP[0]=f1;
		facesP[1]=f2;
		facesP[2]=f3;
		four=false;
	}
	face(int facen,int f1,int f2,int f3,int f4) : facenum(facen){ //overloaded constructor for quad
		facesP[0]=f1;
		facesP[1]=f2;
		facesP[2]=f3;
		facesP[3]=f4;
		four=true;
	}
};

struct uv{
	bool four;
	int * facesP = (int*) malloc(4 *sizeof(int));
	uv(int uva, int uvb, int uvc){
		facesP[0] = uva;
		facesP[1] = uvb;
		facesP[2] = uvc;
		four = false;
	}
	uv(int uva, int uvb, int uvc, int uvd){
		facesP[0] = uva;
		facesP[1] = uvb;
		facesP[2] = uvc;
		four = true;
	}
	
};


struct pose{
			std::vector<physicsLevel::frame*> tailFrames;
			pose(std::vector<physicsLevel::frame*> frames){
				tailFrames = frames;
			}
		};

std::vector<pose*> robotP;

std::vector<coordinate*> pvertP;
std::vector<face*> pfacesP;
std::vector<coordinate*> pnormalsP;

std::vector<coordinate*> rSvertP;
std::vector<face*> rSfacesP;
std::vector<coordinate*> rSnormalsP;

std::vector<coordinate*> tvertP;
std::vector<face*> tfacesP;
std::vector<coordinate*> tnormalsP;

std::vector<coordinate*> svertP;
std::vector<face*> sfacesP;
std::vector<coordinate*> snormalsP;

std::vector<coordinate*> sfvertP;
std::vector<face*> sffacesP;
std::vector<coordinate*> sfnormalsP;

std::vector<coordinate*> evertP;
std::vector<face*> efacesP;
std::vector<coordinate*> enormalsP;

std::vector<coordinate*> fvertP;
std::vector<face*> ffacesP;
std::vector<coordinate*> fnormalsP;


std::vector<coordinate*> trvertP;
std::vector<face*> trfacesP;
std::vector<coordinate*> trnormalsP;

std::vector<coordinate*> mavertP;
std::vector<face*> mafacesP;
std::vector<coordinate*> manormalsP;

std::vector<coordinate*> spvertP;
std::vector<face*> spfacesP;
std::vector<coordinate*> spnormalsP;

std::vector<coordinate*> movvertP;
std::vector<face*> movfacesP;
std::vector<coordinate*> movnormalsP;

std::vector<coordinate*> tavertP;
std::vector<face*> tafacesP;
std::vector<coordinate*> tanormalsP;
std::vector<uv*> taUvPPs;

std::vector<coordinate*>  bvertP;
std::vector<face*> bfacesP;

		
std::vector<coordinate*> dvertP;
std::vector<face*> dfacesP;
std::vector<coordinate*> dnormalsP;

std::vector<coordinate*> pavertP;
std::vector<face*> pafacesP;
std::vector<coordinate*> panormalsP;
		
std::vector<coordinate*> revertP;
std::vector<face*> refacesP;
std::vector<coordinate*> renormalsP;

std::vector<coordinate*> binormalsP;
std::vector<face*> bifacesP;
std::vector<coordinate*> bivertP;

std::vector<coordinate*> throwvertP;
std::vector<face*> throwfacesP;
std::vector<coordinate*> thrownormalsP;

std::vector<face*> biSfacesP;
std::vector<coordinate*> biSvertP;

std::vector<coordinate*> cavertP;
std::vector<face*> cafacesP;
std::vector<coordinate*> canormalsP;

std::vector<coordinate*> rvertP;
std::vector<face*> rfacesP;
std::vector<coordinate*> rnormalsP;

std::vector<coordinate*> kvertP;
std::vector<face*> kfacesP;
std::vector<coordinate*> knormalsP;


std::vector<coordinate*> smvertP;
std::vector<face*> smfacesP;
std::vector<coordinate*> smnormalsP;

std::vector<coordinate*> hvertP;
std::vector<face*> hfacesP;
std::vector<coordinate*> hnormalsP;

int physicsLevel::loadHand(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		hvertP = vertPex;
		hnormalsP = normalsP;
		hfacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	hvertP = vertPex;
	hfacesP = facesP;
	hnormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
}

int physicsLevel::loadRope(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		rvertP = vertPex;
		rnormalsP = normalsP;
		rfacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	rvertP = vertPex;
	rfacesP = facesP;
	rnormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
}

int physicsLevel::loadSmoke(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		smvertP = vertPex;
		smnormalsP = normalsP;
		smfacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	smvertP = vertPex;
	smfacesP = facesP;
	smnormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int physicsLevel::loadKettle(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		kvertP = vertPex;
		knormalsP = normalsP;
		kfacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	kvertP = vertPex;
	kfacesP = facesP;
	knormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
}

int physicsLevel::loadRopeEnd(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		revertP = vertPex;
		renormalsP = normalsP;
		refacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}

	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	revertP = vertPex;
	refacesP = facesP;
	renormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
}

int physicsLevel::loadCog(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		cavertP = vertPex;
		canormalsP = normalsP;
		cafacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}

	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	cavertP = vertPex;
	cafacesP = facesP;
	canormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int physicsLevel::loadCogLocation(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		pavertP = vertPex;
		panormalsP = normalsP;
		pafacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}

	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	pavertP = vertPex;
	pafacesP = facesP;
	panormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}






int physicsLevel::loadCollisionObject(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertP;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	

	if(!in.is_open())
	{
		std::cout << "Nor oepened" << std::endl; //if it's not opened then error message, and return with -1
		return 0;
	}
	char buf[256];	//temp buffer
	int curmat=0;	//the current (default) material is 0, it's used, when we read the faces
	while(!in.eof())
	{
		in.getline(buf,256);	//while we are not in the end of the file, read everything as a string to the coord vector
		coord.push_back(new std::string(buf));
	}
	for(int i=0;i<coord.size();i++)	//and then go through all line and decide what kind of line it is
	{
		if((*coord[i])[0]=='#')	//if it's a comment
			continue;	//we don't have to do anything with it
		else if((*coord[i])[0]=='v' && (*coord[i])[1]==' ')	//if a vertex
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read the 3 floats, which makes up the vertex
			vertP.push_back(new coordinate(tmpx,tmpy,tmpz));	//and put it in the vertex vector

		}else if((*coord[i])[0]=='v' && (*coord[i])[1]=='n')	//if it's a normal vector
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	//basically do the same

			//isnormals=true;
		}else if((*coord[i])[0]=='f')	//if it's a face
		{
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==4)	//if this is a quad
			{
				if(coord[i]->find("//")!=std::string::npos)	//if it's contain a normal vector, but not contain texture coorinate
				{
					sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);	//read in this form
					facesP.push_back(new face(b,a,c,d,e));	//and put to the faces, we don't care about the texture coorinate in this case
																																//and if there is no material, it doesn't matter, what is curmat
				}else if(coord[i]->find("/")!=std::string::npos)	//if we have texture coorinate and normal vectors
				{
					int t[4];	//texture coorinates
					//read in this form, and put to the end of the vector
					sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b,&e,&t[3],&b);
					facesP.push_back(new face(b,a,c,d,e));
				}else{
					//else we don't have normal vectors nor texture coorinate
					sscanf(coord[i]->c_str(),"f %d %d %d %d",&a,&b,&c,&d);
					facesP.push_back(new face(a,b,c,d));		
				}
			}else{	//if it's a triangle
							//do the same, except we use one less vertex/texture coorinate/face number
					if(coord[i]->find("//")!=std::string::npos)
					{
						sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
						facesP.push_back(new face(b,a,c,d));
					}else if(coord[i]->find("/")!=std::string::npos)
					{
						int t[3];
						sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b);
						facesP.push_back(new face(b,a,c,d));
					}else{
						//sscanf(coord[i]->c_str(),"f %d %d %d",&a,&b,&c);
						//faces.push_back(new face(a,b,c);					
					}
			}
		}else if((*coord[i])[0]=='u' && (*coord[i])[1]=='s' && (*coord[i])[2]=='e')	//use material material_name
		{
			continue;
		}else if((*coord[i])[0]=='m' && (*coord[i])[1]=='t' && (*coord[i])[2]=='l' && (*coord[i])[3]=='l')	//material library, a file, which contain
																																																				//all of the materials
		{
			continue;
		}else if((*coord[i])[0]=='v' && (*coord[i])[1]=='t')	//back to the obj file, texture coorinate
		{
			continue;
		}
	}
	spvertP = vertP;
	spnormalsP = normalsP;
	spfacesP = facesP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}



int lowestPoint[200][3];
struct frame{
			std::vector<physicsLevel::coordinate*> tavertP;	//all vertPexes
			std::vector<physicsLevel::face*> tafacesP;					//all facesP
			std::vector<physicsLevel::coordinate*> tanormalsP;	//all normal vectors
			frame(std::vector<physicsLevel::coordinate*> vertPexs, std::vector<physicsLevel::face*> facez, std::vector<physicsLevel::coordinate*> normalz){
				tavertP = vertPexs;
				tafacesP = facez;
				tanormalsP = normalz;
				
			}
			
		};
std::vector<frame*> tailFrames;
int physicsLevel::loadRobot(const char* filename){
		std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;
	std::vector<uv*> uvs;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	furthestYlP = -1000;
	float furthestXl = -1000;
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "didn't load model" << filename << std::endl;

		return -1;
		
	}
	int vertPCounter =0; 
	int faceCounter =0;
	int normalCounter =0;
	bool defined = false;
	bool vertPBool = false;
	bool faceBool = false;
	bool normalBool = false;
	lowestPoint[tailFrames.size()][0] = vertPex.size();
				lowestPoint[tailFrames.size()][1] = facesP.size();
				lowestPoint[tailFrames.size()][2] = normalsP.size();
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0] == 'o'){
			if(defined){
				tailFrames.push_back(new frame(vertPex, facesP, normalsP));
				lowestPoint[tailFrames.size()][0] = vertPex.size();
				lowestPoint[tailFrames.size()][1] = facesP.size();
				lowestPoint[tailFrames.size()][2] = normalsP.size();
			}else{
				defined = true;
			}
		}
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy > furthestYlP){
				furthestYlP = tmpy;	
			}
			if(tmpx > furthestYlP){
				furthestXl = tmpx;	
			}

			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy > furthestYlP){
				furthestYlP = tmpy;	
			}
			if(tmpx > furthestYlP){
				furthestXl = tmpx;	
			}

			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
		

			if(coord[i]->find("//") !=std::string::npos){
				int a,b,c,d,e;
				if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
				{
			  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
					facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
				}else{
					sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
					facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
				}
			}else{
			
				int a,b,c,d,e;
				
				int uva, uvb, uvc, uvd;
				if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
				{
					sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d",&a,&uva,&b,&c, &uvb,&b,&d, &uvc,&b);
					facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
					uvs.push_back(new uv(uva, uvb, uvc));
				}else{
					sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&a, &uva, &b,&c, &uvb, &b, &d, &uvc, &b,&e, &uvd, &b);
					facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
					uvs.push_back(new uv(uva, uvb, uvc, uvd));
				}
			}

		}
	}
	tavertP = vertPex;
	tanormalsP = normalsP;
	tafacesP = facesP;
	tailFrames.push_back(new frame(vertPex, facesP, normalsP));
	robotP.push_back(new pose(tailFrames));
	largestRY[tailFrames.size()-1] = furthestYlP;
	largestRX[tailFrames.size()-1] = furthestXl;
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
	return tailFrames.size();
}
void physicsLevel::loadDomino(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		dvertP = vertPex;
		dnormalsP = normalsP;
		dfacesP = facesP;
		//return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	dvertP = vertPex;
	dfacesP = facesP;
	dnormalsP = normalsP;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int physicsLevel::appendReactionObject(const char* filename){
	std::vector<std::string*> coord;	//every line of code from the obj file
	std::vector<coordinate*> vertPex;	//all vertPexes
	//int textureCounter;
	std::vector<face*> facesP;					//all facesP
	std::vector<coordinate*> normalsP;	//all normal vectors
	//std::vector<unsigned int> texture;//the id for all the textures (so we can delete the textures after use it)
	//std::vector<unsigned int> lists;	//the id for all lists (so we can delete the lists after use it)
	//std::vector<material*> materials;	//all materials
	//std::vector<texcoord*> texturecoordinate;	//all texture coorinate (UV coordinate)
	float furthestYlP = -1000;
	float furthestXl = -1000;
	//textureCounter = 0;
	//preLoadTexture();
	std::ifstream in(filename);	//open the model file
	if(!in.is_open())
	{
		std::cout << "Couldn't load model" << std::endl; //if it's not opened then error message, and return with -1
		return -1;
	}
	char buf[256];	//temp buffer
	int curmat=0;	//the current (default) material is 0, it's used, when we read the facesP
	while(!in.eof())
	{
		in.getline(buf,256);	//while we are not in the end of the file, read everything as a string to the coord vector
		coord.push_back(new std::string(buf));
	}
	for(int i=0;i<coord.size();i++)	//and then go through all line and decide what kind of line it is
	{
		if((*coord[i])[0]=='#')	//if it's a comment
			continue;	//we don't have to do anything with it
		else if((*coord[i])[0]=='v' && (*coord[i])[1]==' ')	//if a vertPex
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read the 3 floats, which makes up the vertPex
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and put it in the vertPex vector
			if(tmpy > furthestYlP){
				furthestYlP = tmpy;	
			}
			if(tmpx > furthestXl){
				furthestXl = tmpx;	
			}
		}else if((*coord[i])[0]=='v' && (*coord[i])[1]=='n')	//if it's a normal vector
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	//basically do the same
			if(tmpy > furthestYlP){
				furthestYlP = tmpy;	
			}
			if(tmpx > furthestXl){
				furthestXl = tmpx;	
			}
			//isnormalsP=true;
		}else if((*coord[i])[0]=='f')	//if it's a face
		{
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==4)	//if this is a quad
			{
				if(coord[i]->find("//")!=std::string::npos)	//if it's contain a normal vector, but not contain texture coorinate
				{
					sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);	//read in this form
					facesP.push_back(new face(b,a,c,d,e));	//and put to the facesP, we don't care about the texture coorinate in this case
																																//and if there is no material, it doesn't matter, what is curmat
				}else if(coord[i]->find("/")!=std::string::npos)	//if we have texture coorinate and normal vectors
				{
					int t[4];	//texture coorinates
					//read in this form, and put to the end of the vector
					sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b,&e,&t[3],&b);
					facesP.push_back(new face(b,a,c,d,e));
				}else{
					//else we don't have normal vectors nor texture coorinate
					sscanf(coord[i]->c_str(),"f %d %d %d %d",&a,&b,&c,&d);
					facesP.push_back(new face(a,b,c,d));		
				}
			}else{	//if it's a triangle
							//do the same, except we use one less vertPex/texture coorinate/face number
					if(coord[i]->find("//")!=std::string::npos)
					{
						sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
						facesP.push_back(new face(b,a,c,d));
					}else if(coord[i]->find("/")!=std::string::npos)
					{
						int t[3];
						sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b);
						facesP.push_back(new face(b,a,c,d));
					}else{
						//sscanf(coord[i]->c_str(),"f %d %d %d",&a,&b,&c);
						//facesP.push_back(new face(a,b,c);					
					}
			}
		}else if((*coord[i])[0]=='u' && (*coord[i])[1]=='s' && (*coord[i])[2]=='e')	//use material material_name
		{
			continue;
		}else if((*coord[i])[0]=='m' && (*coord[i])[1]=='t' && (*coord[i])[2]=='l' && (*coord[i])[3]=='l')	//material library, a file, which contain
																																																				//all of the materials
		{
			continue;
		}else if((*coord[i])[0]=='v' && (*coord[i])[1]=='t')	//back to the obj file, texture coorinate
		{
			continue;
		}
	}

	//std::cout << vertPex.size() << " " << normalsP.size() << " " << facesP.size() << " " << materials.size() << std::endl; 	//test purposes
	//draw
	
	tavertP = vertPex;
	tanormalsP = normalsP;
	tafacesP = facesP;
	tailFrames.push_back(new frame(vertPex, facesP, normalsP));
	largestRY[tailFrames.size()-1] = furthestYlP;
	largestRX[tailFrames.size()-1] = furthestXl;
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	
	return tailFrames.size();
}

void physicsLevel::clearModels(){
	tailFrames.clear();	
}


int physicsLevel::loadObstical(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertPex;
	std::vector<face*> facesP;
	std::vector<coordinate*> normalsP;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		fvertP = vertPex;
		fnormalsP = normalsP;
		ffacesP = facesP;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			vertPex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertPex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYlP){
				furthestYlP = tmpy;	
			}
			normalsP.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				facesP.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				facesP.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	fvertP = vertPex;
	fnormalsP = normalsP;
	ffacesP = facesP;
	obFrames.push_back(new frame(vertPex, facesP, normalsP));
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

