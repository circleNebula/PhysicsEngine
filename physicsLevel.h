#ifndef PHYSICSLEVEL_H
#define PHYSICSLEVEL_H
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
class physicsLevel{
	public:
		

		
		int loadCollisionObject(const char* filename);
		int loadCogLocation(const char* filename);
		int loadCog(const char* filename);
		int appendReactionObject(const char* filename);
		int loadObstical(const char* filename);
		void loadDomino(const char* filename);
		int loadRope(const char* filename);
		int loadRopeEnd(const char* filename);
		int loadKettle(const char* filename);
		void clearModels();
		int loadSmoke(const char* filename);
		int loadHand(const char* filename);
		int loadRobot(const char* filename);
		
		struct coordinate{
			float x,y,z;
			coordinate(float a,float b,float c) : x(a),y(b),z(c) {};
		};
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
		
		struct pose{
			std::vector<physicsLevel::frame*> tailFrames;
			pose(std::vector<physicsLevel::frame*> frames){
				tailFrames = frames;
			}
		};
		int lowestPoint[200][3];
		float largestRY[20];
		float largestRX[20];
		
		std::vector<coordinate*> rvertP;
		std::vector<face*> rfacesP;
		std::vector<coordinate*> rnormalsP;
		
		std::vector<pose*> robotP;
		
		std::vector<frame*> tailFrames;
		std::vector<frame*> obFrames;
		
		std::vector<coordinate*> tvertP;
		std::vector<face*> tfacesP;
		std::vector<coordinate*> tnormalsP;
		
		std::vector<coordinate*> pvertP;
		std::vector<face*> pfacesP;
		std::vector<coordinate*> pnormalsP;
		
		std::vector<coordinate*> rSvertP;
		std::vector<face*> rSfacesP;
		std::vector<coordinate*> rSnormalsP;
		
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
		
		std::vector<coordinate*> bvertP;
		std::vector<face*> bfacesP;
		std::vector<coordinate*> bnormalsP;
		
		std::vector<coordinate*> sqvertP;
		std::vector<face*> sqfacesP;
		
		std::vector<coordinate*> pavertP;
		std::vector<face*> pafacesP;
		std::vector<coordinate*> panormalsP;
		
		std::vector<coordinate*> dvertP;
		std::vector<face*> dfacesP;
		std::vector<coordinate*> dnormalsP;
		
		std::vector<coordinate*> revertP;
		std::vector<face*> refacesP;
		std::vector<coordinate*> renormalsP;
		
		std::vector<coordinate*> binormalsP;
		std::vector<face*> bifacesP;
		std::vector<coordinate*> bivertP;
		
		std::vector<face*> biSfacesP;
		std::vector<coordinate*> biSvertP;
		
		std::vector<coordinate*> throwvertP;
		std::vector<face*> throwfacesP;
		std::vector<coordinate*> thrownormalsP;
		
		std::vector<coordinate*> cavertP;
		std::vector<face*> cafacesP;
		std::vector<coordinate*> canormalsP;
		
		std::vector<coordinate*> kvertP;
		std::vector<face*> kfacesP;
		std::vector<coordinate*> knormalsP;
		
		std::vector<coordinate*> smvertP;
		std::vector<face*> smfacesP;
		std::vector<coordinate*> smnormalsP;

		std::vector<coordinate*> hvertP;
		std::vector<face*> hfacesP;
		std::vector<coordinate*> hnormalsP;
				
		
	private:
		float furthestYlP;
	protected:
};
#endif