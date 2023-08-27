#include "GL/glu.h"
#include <GL/gl.h>
#include "physicsLevel.h"
#include "physicsMain.h"

#include <random>

using namespace std;


physicsLevel levelLoadP;

GLfloat emerald_shininess = 76.8;
float ballHeight = 1;
int ballColours[1000];
bool mapCollisionCounter[1000];
bool fabricFinished = false;
float ballColor[1000][3];
int coolDown = 0;
float divider[200];
int ballSize = 50;
int p = 0;
int rigidSize = 1;
int frameNumber[200];
float rigidX[10][200];
float rigidY[10][200];
float rigidZ[10][200];
float rigidZAngle[10][200];
float rigidXAngle[10][200];
int stopTimer[10][200];
int collidingO[200];
float rigidYAngle[10][200];
float rigidFall[10][200];
bool xrRotation[10][200];
bool zrRotation[10][200];
bool xrDirection[10][200];
bool zrDirection[10][200];
float gravityZ[10][200];
float gravityX[10][200];
float gravityMo[10][200];
bool rxSet[200];
bool rzSet[200];
float fakeMo[200];
float rigidSpeed = 1;
float newRigidXAngle[10][200];
float newRigidZAngle[10][200];
float fallIncrement[200];
float Mo[200];
bool oldXSet[1000];
float ballSpeed[1000];

float robotSkew;

float nragAngleX;
float nragAngleZ;
float ragAngleX;
GLUquadric* sphere;
float ragAngleZ;

int processGradient = 1;

float dominoX[200];
float dominoZ[200];
float dominoY[200];
float dominoVX[200][100];
float dominoVZ[200][100];
float dominoVY[200][100];

float dominoVVX[200][100];
float dominoVVZ[200][100];
float dominoVVY[200][100];
float dominoAngleY[200];
float dominoAngleX[200];
bool dHitGround[200];
int dominoVSize;
int dominoSize;
float dominoHeight;
float dominoScale[200][100];
bool dHitting[200];
float dominoGapX;
float dominoGapY;
float dominoGapZ;

bool gapClosed;

float dropX = 10;
float dropY = 0;
float dropZ = 5;

bool boxMode = false;
bool wind = false;
bool jellyTime = false;
bool rigidBody = true;
bool divisionTime = false;
bool fabricTime = false;
bool customObject = false;
bool robotFalling = true;
bool cogs = false;
bool robot = false;
bool ragdoll = false;
bool stickIt = false;
bool cogReaction = false;
bool cubeTime = false;
bool dominoTime = false;
bool ballPond = false;
bool ropeTime = false;
bool holdingRope = false;
bool fabricRipping = false;
bool kettleTime = false;
bool kettleBoil = false;
bool fluidTime = false;


float kettleSX;
float kettleSY;
float kettleSZ;

float kettleX;
float kettleY;
float kettleZ;

float kettleScale[200];

bool statTime = false;
bool getStats[200];
int ripCounter = -1;

int ropeCounter = 0;
float ropeX[200];
float ropeY[200];
float robeZ[200];
float ropeAngle[200];
float ropeMoX;
bool ropeDirection[10];
bool ropeYDirection[10];
float ropeMoY;
float ropeFriction[200];
float ropeLastX[10];
float ropeLastY[10];
float ropePrio[10];
float oldRopeAngle[200];
float addedSpeed;
int ropeSize;


float slip = 1;
int stick = 180;
int sticky = 1;
int bounce = 0;

int divisionSize; 

float cogX[10];
float cogY[10];
float cogZ[10];
float cogPrio[10];
float obsticleRX[50000];
float obsticleRY[50000];
float obsticleRZ[50000];
int cogSize = 0;
float cogAngle[10];
float cogSpin[10];
int cogFSize = 0;
int cogLength[10];
bool cogLeft[10];



float obsticleX[50000];
float obsticleY[50000];
float obsticleZ[50000];
float obsticleSize[50000];
int obsticleCounter =2;
char obsticleType[50000];

float fabricAngle[2000];
float fabricAngleZ[2000];
float fabricX;
float fabricY;
float fabricZ;


float smashXAngle[200][6];
float smashZAngle[200][6];
float smashFall[200][6];
float smashX[200][6];
float smashZ[200][6];
float smashY[200][6];
float smashNewXAngle[200][6];
float smashNewZAngle[200][6];

int ballfacesP[200][3000][4];

int divisionSplit;
int divisionEnd;


int ripCount = 0;
int rip[10];

bool meltingTime = false;
bool collidedM[200][2000];

bool robotDefined = false;

int robotSize = 0;
int fabricTop = 6;
bool horizontal = false;
float rigidIncrement[10][200];
float heightSkew[200];
float jellyMo[10][200][1000][4];
float jellyPrio[10][200];
float jellyFall[10][200][1000][4];

int jellySize = 10;
int ballJSize[10][200];
int splitSize[200];
float velocity;
int splitFrag[200][6][1000];
int splitCounter[200][6];

float Balls1[4][200][3000][3];
float oldBalls1[4][200][3000][3];
float BallnormalsP[200][3000][3];

float heatColour[200][3000][3];
bool heatMap = true;

bool handTime = false;
float handX[15];
float handY[15];
float handZ[15];
int handCount = 15;

bool marbleMoved; 

int rigidTop; 
bool hitGround[200];

int ouraFace[200][3000][10][4];
int ourafacesP[200][3000][10][4];
int ouraFaceCounter[200][3000][4];

float marble[200][3];
int marbleSize;
float marbleAngle[200][2];
int constJelly[200][100];

float marbleSpawn[3];
float weight[200];

float marbleFall[200];
float marbleMo[200];

bool marbleTime = false;

float dominoSX;
float dominoSY;
float dominoSZ;

int dominoCount;
int dominoCounter;
int currentDominoAngle;
int collidingIP = -1;

float handRX[1000];
float handRY[1000];
float handRZ[1000];

int jellyCollision[200];

int handCounter;

int fluidSize;


float dirtX2[100];
float dirtY2[100];
int dirtSize2;

float grassX2[100];
float grassY2[100];
int grassSize2;

float woodX2[100];
float woodY2[100];
int woodSize2;

float stoneX2[100];
float stoneY2[100];
int stoneSize2;


float marbleDimensions;


void physicsMain::setDirt(float* X, float* Y, int size){

	dirtSize2 = size;
	
	for(int i = 0; i < dirtSize2; i++){
		dirtX2[i] = X[i];
		dirtY2[i] = Y[i];
	}
}


void physicsMain::setGrass(float* X, float* Y, int size){

	grassSize2 = size;
	
	for(int i = 0; i < grassSize2; i++){
		grassX2[i] = X[i];
		grassY2[i] = Y[i];
	}
}

void physicsMain::setWood(float* X, float* Y, int size){

	woodSize2 = size;
	
	for(int i = 0; i < woodSize2; i++){
		woodX2[i] = X[i];
		woodY2[i] = Y[i];
	}
}

void physicsMain::setStone(float* X, float* Y, int size){
	
	stoneSize2 = size;
	
	for(int i = 0; i < stoneSize2; i++){
		stoneX2[i] = X[i];
		stoneY2[i] = Y[i];
	}
}



void physicsMain::setHand(float x, float y, float z){
	handTime = true;
	handX[0] = x;
	handY[0] = y;
	handZ[0] = z;
}


float physicsMain::get_random()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(e);
}
void physicsMain::setMarbleSpawn(float x, float y, float z){
	marbleSpawn[0] = x;
	marbleSpawn[1] = y;
	marbleSpawn[2] = z;
}
void physicsMain::initMarble(){
	marbleMoved = true;
	marbleTime = true;
	if(processGradient == 4){
		setMarbleSpawn(147, 1, -10);
	}else{
		setMarbleSpawn(10, 0, 0);
	}
	marbleDimensions = 2;
	int xCounter = 0;
	int yCounter = 0;
	for(int i = 0; i < marbleSize; i++){
		if(i % 5 ==0){
			xCounter = 0;
			yCounter += 3;
		}else{
			marbleMo[i] = 0.6;
			marbleFall[i] = 0.05;
			marble[i][0] = marbleSpawn[0] + xCounter * (marbleDimensions* 10);
			marble[i][1] = marbleSpawn[1] + yCounter * marbleDimensions;
			marble[i][2] = marbleSpawn[2];
			marbleAngle[i][1] = 180;
			marbleAngle[i][0] = 0;
			xCounter++;
		}
		
	}
	
}

void physicsMain::initFluid(){ // this program sets up the spawn of the spheres, using a typewriter style, it then sets the initial attributes such as gravity and momentum
	jellyTime = true;
	
	fluidSize = 900;
	float yCounter = 1;
	float typeWriter = 0;
	fluidTime = true;
	levelLoadP.loadCollisionObject("Objects/box.obj");
	setObsticleCollisions(true);
	if(fluidTime){
	//cout  << "here " << ballSize << endl;
		for(int i = 0; i < 10; i++){
			rip[i] = -1;
		}
		for (int i = 0; i < fluidSize; i++) {
			ballSpeed[i] = velocity;
			ballMo[i] = (0.5);
			fakeMo[i] = 0;
			fallMo[i] = 0.01;
		}
		for(int i = 0; i < fluidSize; i++){
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
	}
		//if(!horizontal){
			for (int i = 0; i < fluidSize; i++) {
				
				Balls1[0][0][i][0] = (typeWriter - i) * ((ballHeight * 2) + 0.1) + fabricX;
				Balls1[0][0][i][2] = fabricZ;
				Balls1[0][0][i][1] = yCounter * ((ballHeight * 2) + 0.1);
				

				fabricAngle[i] = 0;
				fabricAngleZ[i] = 0;
				oldBalls1[0][0][i][0] = Balls1[0][0][i][0];
				oldBalls1[0][0][i][1] = Balls1[0][0][i][1];
				oldBalls1[0][0][i][2] = Balls1[0][0][i][2];
	
				if (i % fabricTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  fabricTop;
				}
			}
		
	}
	ballHeight = 0.2;
	jellyTime = false;
	divisionTime = false;
}


void physicsMain::material(int dlist, GLfloat * ambient, GLfloat * diffuse,
  GLfloat * specular, GLfloat shininess)
{ // using opengl to set a material such as "PHONG"
  glNewList(dlist, GL_COMPILE);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
  glEndList();
}
void physicsMain::resetDomino(){ // Respawns the domino
	int oldSize = 150;
	dominoCount = 0;
	dominoCounter = 0;
	
	dominoSize = 0;
	currentDominoAngle = 0;
	dominoGapX = 0;
	dominoGapZ = 0;
	dominoGapY = 0;
	gapClosed = false;
	
	for(int c = 0; c < oldSize; c++){
		dominoX[c] = 0;
		dominoZ[c] = 0;

			dHitting[c] = false;
			dHitGround[c] = false;

			dominoVSize = 0;
			for(int i =0; i < levelLoadP.dfacesP.size(); i+= 2){
				dominoScale[dominoSize][i]  = 0.32;
				dominoVX[dominoSize][i] = levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->x;
				dominoVY[dominoSize][i] = levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->y;
				dominoVZ[dominoSize][i] = levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->z;
				
				dominoVSize++;

				
			}
			dominoSize++;
		}
		dominoX[0] = dominoSX;
	dominoY[0] = dominoSY;
	dominoZ[0] = dominoSZ;
}
float* physicsMain::rotateY(float &valueX, float &valueY, float &valueZ, float angleY){ //rotates only the y axis also using the x axis
										float* angleReturn = (float*) malloc(3 * sizeof(float));
										float xRadians = angleY* (3.14159/180);
										float x2 = cos(xRadians)*valueX -sin(xRadians)* valueY;
										angleReturn[1] = sin(xRadians)*valueX +cos(xRadians)*valueY;
										angleReturn[0] = x2;
										angleReturn[2] = valueZ;
										
										return angleReturn;
}

float* physicsMain::rotateZ(float &valueX, float &valueY, float &valueZ, float angleZ){ //rotates the z axis also using the y axis
	float* angleReturn = (float*) malloc(3 * sizeof(float));
		float zRadians =  angleZ * (3.14159/180);
			float z2 = cos(zRadians)*valueZ -sin(zRadians)*valueX;
			angleReturn[0] = sin(zRadians)*valueZ +cos(zRadians)*valueX;
			angleReturn[2] = z2;
			angleReturn[1] = valueY;
			return angleReturn;
			
	
}
float* physicsMain::rotateXZ(float &valueX, float &valueY, float &valueZ, float angleX, float angleZ){ // rotates the x and z coordinates using the y axis
	float xRadians = angleX* (3.14159/180);
	float zRadians = angleZ* (3.14159/180);
	float* angleReturn = (float*) malloc(3 * sizeof(float));
	angleReturn[1] = valueY;
	
	
	float x2 = cos(xRadians)*valueX -sin(xRadians)*angleReturn[1];
	angleReturn[1] = sin(xRadians)*valueX +cos(xRadians)*angleReturn[1];
	angleReturn[2] = x2;
	
	float z2 = cos(zRadians)*valueZ-sin(zRadians)*angleReturn[1];
	angleReturn[1] = sin(zRadians)*valueZ +cos(zRadians)*angleReturn[1];
	angleReturn[0] = z2;
	

	
						
	return angleReturn;
	
}
void physicsMain::TamperJelly(float increase, float angleX, float angleY, float angleZ, int gradient, int start, int r){ // tampers with the model, extruding points. 
	float inc = rigidIncrement[p][r]*2;

	float use = increase;
	for(int c = start; c < start +inc; c++){

		if(c < ballJSize[p][r]){	

			for(int cv = 0; cv < 3; cv++){
														
				Balls1[cv][r][c][0] += (gradient*use) * cos(angleX);
				Balls1[cv][r][c][1] += (gradient*use) * sin(angleY);
				Balls1[cv][r][c][2] += (gradient*use) * cos(angleZ);
																	
																	
				Balls1[cv][r][c][0] -= (Balls1[cv][r][c][0] - oldBalls1[cv][r][c][0])/gradient;
				Balls1[cv][r][c][1] -= (Balls1[cv][r][c][1] - oldBalls1[cv][r][c][1])/gradient;
				Balls1[cv][r][c][2] -= (Balls1[cv][r][c][2] - oldBalls1[cv][r][c][2])/gradient;

																
				}
			}
		}
	}
	
void physicsMain::restoreFromJelly(int gradient, int start, int r){ // moves the tampered model back to original position
	float inc = rigidIncrement[p][r]*2;

	for(int c = start; c >  (start - inc); c--){ 
		if(c > 0){
			for(int cv = 0; cv < 4; cv++){
				Balls1[cv][r][c][0] -= (Balls1[cv][r][c][0] - oldBalls1[cv][r][c][0])/(gradient);
				Balls1[cv][r][c][1] -= (Balls1[cv][r][c][1] - oldBalls1[cv][r][c][1])/(gradient);
				Balls1[cv][r][c][2] -= (Balls1[cv][r][c][2] - oldBalls1[cv][r][c][2])/(gradient);
											
			}
		}	
	}
}
void physicsMain::UpdateFace(int c, int r){ // updates the points connected to the moved point, only one face
	for(int cv = 0; cv < 4; cv++){


					for(int x = 0; x < ouraFaceCounter[r][c][cv]; x++){
											//	if(jellyPrio[p][r]
						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][0] = Balls1[cv][r][c][0];
						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][1] = Balls1[cv][r][c][1];
						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][2] = Balls1[cv][r][c][2];
											

											
					}

			}
}
void physicsMain::updateFaces(int start, int r){ // updates the points connected to the moved point, moving through the gaps in processing
	float inc = rigidIncrement[p][r] *2;

	for(int c = start; c > (start - inc); c--){ 
		if(c > 0){
			for(int cv = 0; cv < 4; cv++){

				if((Balls1[cv][r][c][0] - oldBalls1[cv][r][c][0]) != 0 ){

					for(int x = 0; x < ouraFaceCounter[r][c][cv]; x++){

						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][0] = Balls1[cv][r][c][0];
						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][1] = Balls1[cv][r][c][1];
						Balls1[ourafacesP[r][c][x][cv]][r][ouraFace[r][c][x][cv]][2] = Balls1[cv][r][c][2];
											

											
					}

				}
			}
		}
	}
}
float* physicsMain::rotateX(float &valueX, float &valueY, float &valueZ, float angleX){ //rotates the x  also using the y axis
										float* angleReturn = (float*) malloc(3 * sizeof(float));

										float xxRadians = (angleX)* (3.14159/180);
										float z22 = sin(xxRadians)*valueX -cos(xxRadians)* valueZ;
										float x22 = cos(xxRadians)*valueX -sin(xxRadians)* valueZ;
	
										angleReturn[0] = x22;
										angleReturn[2] = z22;

										angleReturn[1] = valueY;
										
										return angleReturn;
										
										
}
float* physicsMain::getCustomCollidingAngle(float x, float y, float z, float x2, float y2, float z2, float dimensions){ // compares only two collisions
	float* angleReturn = (float*) malloc(3 * sizeof(float));
	float differenceX = x - x2;
									float differenceZ = z - z2;
									float differenceY = y - y2;
									if(differenceX < 1 && differenceX > -1){
										if(differenceY < 1 && differenceY > -1){
											if(differenceZ < 1 && differenceY > -1){
												if(collision(x, y, dimensions, x2, y2, dimensions)){

													if(collision(z, y, dimensions, z2, y2, dimensions)){
															angleReturn[0] = (atan2(y2 - y, x2 - x) * 180 / 3.14159);
															angleReturn[1] = (atan2(y2-  y, z2 - z) * 180 / 3.14159);
															angleReturn[2] = (atan2(y2, y) * 180/ 3.14159);
															return angleReturn;
												
													}
												}
											}
										}
									}
									
	angleReturn[0] = -1;
	angleReturn[1] = -1;
	return angleReturn;
									
			
}

float* physicsMain::getRobotCollidingAngle(float &x, float &y, float &z, float dimensions){ //collision with no rendering techniques. 
	float* angleReturn = (float*) malloc(3 * sizeof(float));
	for (int o = 0; o < obsticleCounter; o++) {
									float differenceX = x - obsticleX[o];
									float differenceZ = z - obsticleZ[o];
									float differenceY = y - obsticleY[o];
								//	if(differenceX * differenceX < 5){
								//		if(differenceY * differenceY < 5){
								//			if(differenceZ * differenceZ < 5){
											
												//bool hasCollided = collision(x, y, 1, obsticleX[o], obsticleY[o], obsticleSize[o]);
												if(collision(x, y, dimensions, obsticleX[o], obsticleY[o], obsticleSize[o])){
													//bool hasCollided2 = collision(z, y, 1, obsticleZ[o], obsticleY[o], obsticleSize[o]);
													if(collision(z, y, dimensions, obsticleZ[o], obsticleY[o], obsticleSize[o])){
														
														angleReturn[0] = (atan2(obsticleY[o] - y, obsticleX[o] - x) * 180 / 3.14159);
														angleReturn[1] = (atan2(obsticleY[o]-  y, obsticleZ[o] - z) * 180 / 3.14159);
														angleReturn[2] = (atan2(y, obsticleY[o])* 180 /3.14159);
														collidingIP = o;
														return angleReturn;
													}
													
												}
								//			}
								//		}
								//	}
									
								//	}
									
		}
		collidingIP = -1;
		angleReturn[0] = -1;
		angleReturn[1] = -1;
		return angleReturn;
	}
float* physicsMain::getCollidingAngle(float &x, float &y, float &z, float dimensions){ //compares the object to the terrain and checks for collision, returning the angle of clipping
	float* angleReturn = (float*) malloc(3 * sizeof(float));
	int counter = 5;
	
	
	for(int i = 0; i < woodSize2; i++){
		for (int o = 0; o < obsticleCounter; o+= counter) {
										//float differenceX = x - obsticleX[o];
										float differenceZ = z - (obsticleZ[o] + woodX2[i]);


									//	if(differenceX < dif && differenceX > -dif){
										//	if(differenceY < dif && differenceY > -dif){
												if(differenceZ * differenceZ < 2){
												
													counter = 1;
													if(collision(x, y, dimensions, obsticleX[o], obsticleY[o] + woodY2[i], obsticleSize[o])){
		
														if(collision(z, y, dimensions, obsticleZ[o] + woodX2[i], obsticleY[o] + woodY2[i], obsticleSize[o])){
															
															angleReturn[0] = (atan2((obsticleY[o] + woodY2[i]) - y, obsticleX[o] - x) * 180 / 3.14159);
															angleReturn[1] = (atan2((obsticleY[o] + woodY2[i]) -  y, (obsticleZ[o] + woodX2[i]) - z) * 180 / 3.14159);
															angleReturn[2] = (atan((obsticleY[o] + woodY2[i]) - y) * 180/ 3.14159);
		
															collidingIP = o;
															return angleReturn;
														}
														
													}
												}else{
													counter++;
												}

										
			}
		} 
			for(int i = 0; i < grassSize2; i++){
		for (int o = 0; o < obsticleCounter; o+= counter) {
										//float differenceX = x - obsticleX[o];
										float differenceZ = z - (obsticleZ[o] + grassX2[i]);

		
									//	if(differenceX < dif && differenceX > -dif){
										//	if(differenceY < dif && differenceY > -dif){
												if(differenceZ * differenceZ < 2){
												
													counter = 1;
													if(collision(x, y, dimensions, obsticleX[o], obsticleY[o] + grassY2[i], obsticleSize[o])){
		
														if(collision(z, y, dimensions, obsticleZ[o] + grassX2[i], obsticleY[o] + grassY2[i], obsticleSize[o])){
															
															angleReturn[0] = (atan2((obsticleY[o] + grassY2[i]) - y, obsticleX[o] - x) * 180 / 3.14159);
															angleReturn[1] = (atan2((obsticleY[o] + grassY2[i]) -  y, (obsticleZ[o] + grassX2[i]) - z) * 180 / 3.14159);
															angleReturn[2] = (atan((obsticleY[o] + grassY2[i]) - y) * 180/ 3.14159);
		
															collidingIP = o;
															return angleReturn;
														}
														
													}
												}else{
													counter++;
												}

										
			}
		}
		
			for(int i = 0; i < stoneSize2; i++){
				
				
				//cout << x << stoneX2[i] << endl;
			//	cout << 'y' << y <<  ":" << stoneY2[i] << endl;
	//	cout << z << 1<< endl;
		for (int o = 0; o < obsticleCounter; o+= counter) {
										//float differenceX = x - obsticleX[o];
										float differenceZ = z - (obsticleZ[o] + stoneX2[i]);

										//float differenceY = y - obsticleY[o];

									//	if(differenceX < dif && differenceX > -dif){
										//	if(differenceY < dif && differenceY > -dif){
												if(differenceZ * differenceZ < 2){
													

												
													counter = 1;
													if(collision(x, y, dimensions, obsticleX[o], obsticleY[o] + stoneY2[i], obsticleSize[o])){
		
														if(collision(z, y, dimensions, obsticleZ[o] + stoneX2[i], obsticleY[o] +stoneY2[i], obsticleSize[o])){
															
															angleReturn[0] = (atan2((obsticleY[o] + stoneY2[i]) - y, obsticleX[o] - x) * 180 / 3.14159);
															angleReturn[1] = (atan2((obsticleY[o] + stoneY2[i])-  y, (obsticleZ[o] + stoneX2[i]) - z) * 180 / 3.14159);
															angleReturn[2] = (atan((obsticleY[o] + stoneY2[i]) - y) * 180/ 3.14159);
															
													//		cout << 'helloworld' << endl;
															
															collidingIP = o;
														//	cout << "collided" << angleReturn[0] << endl;
															
															return angleReturn;
														}
														
													}
												}else{
													counter++;
												}

										
			}
		}
		
		
			for(int i = 0; i < dirtSize2; i++){
		for (int o = 0; o < obsticleCounter; o+= counter) {
										//float differenceX = x - obsticleX[o];
										float differenceZ = z - (obsticleZ[o] + dirtX2[i]);


									//	if(differenceX < dif && differenceX > -dif){
										//	if(differenceY < dif && differenceY > -dif){
												if(differenceZ * differenceZ < 2){
												
													counter = 1;
													if(collision(x, y, dimensions, obsticleX[o], obsticleY[o] + dirtY2[i], obsticleSize[o])){
		
														if(collision(z, y, dimensions, obsticleZ[o] + dirtX2[i], obsticleY[o] + dirtY2[i], obsticleSize[o])){
															
															angleReturn[0] = (atan2((obsticleY[o]  + dirtY2[i]) - y, obsticleX[o] - x) * 180 / 3.14159);
															angleReturn[1] = (atan2((obsticleY[o] +  dirtY2[i]) - y, (obsticleZ[o] + dirtX2[i]) - z) * 180 / 3.14159);
															angleReturn[2] = (atan((obsticleY[o] + dirtY2[i]) - y) * 180/ 3.14159);
		
															collidingIP = o;
															return angleReturn;
														}
														
													}
												}else{
													counter++;
												}

										
			}
		}
		collidingIP = -1;
		angleReturn[0] = -1;
		angleReturn[1] = -1;
		return angleReturn;
	}
	
void physicsMain::loadRope(){ // initialized rope objects
	ropeTime = true;
	holdingRope = true;
	ropeSize = 8;
	ropeCounter = 20;
	levelLoadP.loadRope("Objects/movingObsticles/rope.obj");
	levelLoadP.loadRopeEnd("Objects/movingObsticles/ropeEnd.obj");
	
}
void physicsMain::setDominoGap(float x, float y, float z){
	dominoGapX += x;
	dominoGapY += y;
	dominoGapZ += z;
	gapClosed = false;
}
void physicsMain::initDomino(int angle, bool turn){ // intialised dominos, 5 at a time, if there is a rotation, it will turn the dominoes using the 5 spawning
	
	dominoTime = true;
	if(processGradient!= 4){
		jellyTime = false;
		robotFalling = false;
		divisionTime = false;
		ballPond = false;
		fabricTime = false;
	
		flatSurface();
		setObsticleCollisions(true);
	}
	levelLoadP.loadDomino("Objects/MovingObsticles/domino.obj");
	dominoHeight = 3.5;
	int increase = 5;
	increase += angle / 35;
	for(int i = dominoCount; i < dominoCount + increase; i++){ //colour
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
	}
	float currentAngle = dominoAngleX[dominoCounter];
	float oldAngle = currentAngle;
	
	for(int i = dominoCount+1; i < dominoCount + increase; i++){ //domino count is how many there already were.
		
		dominoAngleY[i] = 360;
		int loopCount = 0;
		//for(int v = 0; v < ballSize; v++){
			if(turn == true){
				currentAngle += angle/5; // turn using the angle divided by 5
				dominoAngleX[i] = currentAngle;
				currentDominoAngle = dominoAngleX[i];
				

				dominoX[i] = dominoX[dominoCounter] + (3.4) * cos(dominoAngleX[i] * (3.14159/180));
				dominoZ[i] = dominoZ[dominoCounter] + (3.4) * sin(dominoAngleX[i] * (3.14159/180));
				dominoY[i] =  10;
				
				
				
				loopCount = i;
				dominoCounter = loopCount;
			}
			if(turn == false){
				
				dominoAngleX[i] = currentDominoAngle;
				dominoX[i] = dominoX[dominoCounter] + (3.4) * cos(dominoAngleX[i] * (3.14159/180));
				dominoZ[i] = dominoZ[dominoCounter] + (3.4) * sin(dominoAngleX[i] * (3.14159/180));
				loopCount = i;
				dominoY[i] =  10;
				dominoCounter = loopCount;
			}
			
			if(!gapClosed){
					gapClosed = true;
					dominoX[i] += dominoGapX;
					dominoY[i] += dominoGapY;
					dominoZ[i] += dominoGapZ;
				}
			//}
			
		//}
	}
	
	
		
		
		dominoCount += increase;
	
}
void physicsMain::testMap(){ // load a specific testing map
	char* testMap = "Objects/testObsticle.obj";
	levelLoadP.loadCollisionObject(testMap);	
	
	setObsticleCollisions(true);
}
void physicsMain::randomMap(){ //pick from the maps already there. 
	int aNumber = rand()% 3;

	string theString = "Objects/random/collisionObject";
	theString += std::to_string(aNumber);
	theString += ".obj";
	char* toChar = (char*) theString.c_str();
	cout << toChar << endl;
	levelLoadP.loadCollisionObject(toChar);	
	
	setObsticleCollisions(true);
	
}
void physicsMain::initRigid(){
	process(3);
	float yCounter = 1;
	float typeWriter = 0;
	boxMode = true;
	yCounter = 1;
	typeWriter = 0;
	for(int i = 0; i < ballSize; i++){
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
	}
	float fullLrgY = 0;
	float fullLrgX = 0;
		for(int i = 0; i < levelLoadP.tailFrames.size(); i++){
			if(levelLoadP.largestRY[i] > fullLrgY){
				fullLrgY = levelLoadP.largestRY[i];
			}
			if(levelLoadP.largestRX[i] > fullLrgX){
				fullLrgX = levelLoadP.largestRX[i];
			}
		}
	for(int i = 0; i < ballSize; i++){
		mapCollisionCounter[i]= false;
		frameNumber[i] = (int) rand() % levelLoadP.tailFrames.size();
		heightSkew[i] = 5;
		rigidIncrement[p][i] = 0.1 * levelLoadP.tailFrames[frameNumber[i]]->tafacesP.size();
		

		xrRotation[p][i] = false;
		zrRotation[p][i] = false;
		xrDirection[p][i] = false;
		zrDirection[p][i] = false;
		float xIncrement = 0; //15
			float yIncrement = 0; //20
			float zIncrement =0; //5
			

		rigidFall[p][i] = 0.3;
		rigidY[p][i] = yCounter * ((ballHeight* 2) + (ballHeight*fullLrgY) + 0.1) + dropX;
		rigidX[p][i] = ((typeWriter - i) * ((ballHeight * 2)+ (ballHeight*fullLrgX) + ballHeight)) + dropY;
		rigidZ[p][i] = dropZ;
		if (i % fabricTop == 0) {
            yCounter+= 1 ;
            typeWriter +=  fabricTop;
        }
		

		rigidZAngle[p][i] = 0;
		fakeMo[i] = 0; 
		rigidXAngle[p][i] = 0;
		rigidYAngle[p][i] = 0;

		newRigidXAngle[p][i] = 0;
		newRigidZAngle[p][i] = 0;
		Mo[i] = 0.3;
	}
}
void physicsMain::setHeat(bool value){ // increase heatmap
	heatMap = value;
}
float physicsMain::length(float x, float y, float x2, float y2){ // get length of 2 centres.
	return sqrt(((x-x2) * (x-x2)) + ((y - y2) * (y-y2)));
}

void physicsMain::moveRopeX(float value){ // move x of rope from a 1D array.

	for(int i = ropeSize-1; i > ropeSize -2; i--){
	for(int v = i * ropeCounter; v < (i+1) * ropeCounter; v++){
		float decrease = (v - (i * ropeCounter)) + 3 ;

			ropeAngle[v] += ((ropeCounter - decrease) * 2) * 3.14159/180;
			ropeY[v] += sin(ropeAngle[v] * 3.14159/180);

		ropeX[v] += value / decrease;
		

		
	}
	}
}

void physicsMain::letGo(){ // let go and "swing" the rope.
	cout << "going" << endl;
	for(int i = ropeSize-1; i > ropeSize -2; i--){
		if(ropeX[i*ropeCounter] > 0){
			ropeDirection[i] = true;
			ropeYDirection[i] = true; 
		}else{
			ropeDirection[i] = true;
			ropeYDirection[i] = false; 
		}
	}
	for(int i = ropeSize-1; i > ropeSize -2; i--){
		ropeLastX[i] = ropeX[i*ropeCounter];
		ropeLastY[i] = ropeY[i*ropeCounter];
	}
	
	for(int i = ropeSize-1; i > ropeSize -2; i--){
		for(int v = i * ropeCounter; v < (i+1) * ropeCounter; v++){
			oldRopeAngle[v] = ropeAngle[v];
			
		}
	}
	
	holdingRope = false;
}

bool physicsMain::isRope(){ // is it ropetime?
	return ropeTime;
}
void physicsMain::resetPhysics(){ // a overiding reset in case it's needed
	for(int r = 1; r < ballSize; r++){
		xrDirection[p][r] = false;
		zrDirection[p][r] = false;
		rigidXAngle[p][r] = 0;
		rigidZAngle[p][r] = 0;
		newRigidZAngle[p][r] = 0;
		newRigidXAngle[p][r] = 0;
		rigidFall[p][r] = 0.5;
		for (int v = 0; v < ballJSize[p][r]; v++) {
			jellyMo[p][r][v][0] = velocity;
			jellyMo[p][r][v][1] = velocity;
			jellyMo[p][r][v][2] = velocity;
			jellyMo[p][r][v][3] = velocity;
		}
	}
	
}
void physicsMain::swap(float *xp, float *yp) //bubble sort swap for float numbers
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void physicsMain::swapFace(int *xp, int *yp) // bubble sort swap for integers 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void physicsMain::sortByX(int r){ //sort by Z, but it says X
	int n = ballJSize[p][r];
	 int i, j; 
	   bool swapped; 
	   for (i = 0; i < n-1; i++) 
	   { 
		 swapped = false; 

			 for (j = 0; j < n-i-1; j++) 
			 { 
				if (Balls1[0][r][j][0] > Balls1[0][r][j+1][0]) 
				{ 
					swap(&Balls1[0][r][j][0], &Balls1[0][r][j+1][0]);
					swap(&Balls1[0][r][j][1], &Balls1[0][r][j+1][1]);
					swap(&Balls1[0][r][j][2], &Balls1[0][r][j+1][2]);
					
					swap(&Balls1[1][r][j][0], &Balls1[1][r][j+1][0]);
					swap(&Balls1[1][r][j][1], &Balls1[1][r][j+1][1]);
					swap(&Balls1[1][r][j][2], &Balls1[1][r][j+1][2]);
					
					swap(&Balls1[2][r][j][0], &Balls1[2][r][j+1][0]);
					swap(&Balls1[2][r][j][1], &Balls1[2][r][j+1][1]);
					swap(&Balls1[2][r][j][2], &Balls1[2][r][j+1][2]);
					
					swap(&oldBalls1[0][r][j][0], &oldBalls1[0][r][j+1][0]);
					swap(&oldBalls1[0][r][j][1], &oldBalls1[0][r][j+1][1]);
					swap(&oldBalls1[0][r][j][2], &oldBalls1[0][r][j+1][2]);
					
					swap(&oldBalls1[1][r][j][0], &oldBalls1[1][r][j+1][0]);
					swap(&oldBalls1[1][r][j][1], &oldBalls1[1][r][j+1][1]);
					swap(&oldBalls1[1][r][j][2], &oldBalls1[1][r][j+1][2]);
					
					swap(&oldBalls1[2][r][j][0], &oldBalls1[2][r][j+1][0]);
					swap(&oldBalls1[2][r][j][1], &oldBalls1[2][r][j+1][1]);
					swap(&oldBalls1[2][r][j][2], &oldBalls1[2][r][j+1][2]);
					
					swap(&BallnormalsP[r][j][0], &BallnormalsP[r][j+1][0]);
					swap(&BallnormalsP[r][j][1], &BallnormalsP[r][j+1][1]);
					swap(&BallnormalsP[r][j][2], &BallnormalsP[r][j+1][2]);
					
					swapFace(&ballfacesP[r][j][0], &ballfacesP[r][j+1][0]);
					swapFace(&ballfacesP[r][j][1], &ballfacesP[r][j+1][1]);
					swapFace(&ballfacesP[r][j][2], &ballfacesP[r][j+1][2]);
					

				   swapped = true; 
				} 
			 } 
		// }
	  
		 // IF no two elements were swapped by inner loop, then break 
		 if (swapped == false) 
			break; 
	   } 
	
}

float* physicsMain::getBallColor(int r){
	float* color = (float*)malloc(sizeof(float)*3);
	color[0] = ballColor[r][0];
	color[1] = ballColor[r][1];
	color[2] = ballColor[r][2];
	return color;
}
bool handCollided;
int jellyCounter = 0;
void physicsMain::initPhysics(bool load){ //main initializer, works for fabric, rope, division, soft and hard bodies. 
	handCollided = false;
	float yCounter = 1;
	float typeWriter = 0;
	if(load){
	if(robot){
		robot = false;
		process(processGradient);
	}

	p =0; 

	for(int i = 0; i < ballSize; i++){ //colour
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
			glColor4f(get_random(), get_random(), get_random(), 1);
			ballColor[i][0] = get_random();
			ballColor[i][2] = get_random();
			ballColor[i][1] = get_random();
	}
	
	
	
	
	yCounter = 1;
	typeWriter = 0;

		
	if(ropeTime){
			ropeDimensions = 0.5;
			for(int v = 0; v < ropeSize; v++){
				for(int i = v * ropeCounter; i < (v + 1) * ropeCounter; i++){
					ropeX[i] = (1 * (v+ 2) * 3 )+ 3;
					ropeY[i] = ((i +1 - ((v + 1) * ropeCounter))* 2) + 40;
					ropeZ[i] = 1;
					ropeAngle[i] = 0;
					
					
				}
				ropeLastX[v] = 0;
				ropeLastY[v] = 0;
			}
			
			addedSpeed = 5;
			ropeMoX = 0;
			ropeMoY = 0;
		
	}
	fabricSize = 300;
	float fabricHeight = 0.5;
	
	if(fabricTime){

		for(int i = 0; i < 10; i++){
			rip[i] = -1;
		}
		for (int i = 0; i < fabricSize; i++) {
			ballSpeed[i] = velocity;
			ballMo[i] = (0.7);
			if(fabricTime){
				ballMo[i] = 0.0;
				oldXSet[i] = false;
			}
			fakeMo[i] = 0;
			fallMo[i] = 0.01;
		}
		for(int i = 0; i < fabricSize; i++){
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
	}

			for (int i = 0; i < fabricSize; i++) {
				
				if(fabricTest && processGradient != 4){
					fabricY = 3;
					fabricZ = -3;
					fabricX = 10;
				}else if(processGradient != 4){
					fabricY = 10;
				}
				Balls1[0][0][i][0] = yCounter * ((fabricHeight * 2) + 0.1) + fabricX;
				Balls1[0][0][i][2] = ((typeWriter - i) * ((fabricHeight * 2) + fabricHeight)) + fabricZ;
				Balls1[0][0][i][1] = fabricY;
				
	
				fabricAngle[i] = 0;
				oldBalls1[0][0][i][0] = Balls1[0][0][i][0];
				oldBalls1[0][0][i][1] = Balls1[0][0][i][1];
				oldBalls1[0][0][i][2] = Balls1[0][0][i][2];

				if (i % fabricTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  fabricTop;
				}
			}
		
	}
	yCounter = 1;
	typeWriter = 0;
	int ballCounter = 0;
	divisionSplit = 1;
	divisionEnd = 0;
	if(jellyTime){

			divisionSplit = jellySize;
			divisionEnd = jellySize;
			float fullLrgY = 0;
			float fullLrgX = 0;
			for(int i = 0; i < levelLoadP.tailFrames.size(); i++){
				if(levelLoadP.largestRY[i] > fullLrgY){
					fullLrgY = levelLoadP.largestRY[i];
				}
				if(levelLoadP.largestRX[i] > fullLrgX){
					fullLrgX = levelLoadP.largestRX[i];
				}
			}

			for(int r = 1; r < jellySize; r++){
				hitGround[r] = false;
				

				xrDirection[p][r] = false;
				mapCollisionCounter[r] = false;
				zrDirection[p][r] = false;
				rigidXAngle[p][r] = 0;
				rigidZAngle[p][r] = 0;
				rigidYAngle[p][r] = -90;
				newRigidZAngle[p][r] = 0;
				newRigidXAngle[p][r] = 0;
				rigidFall[p][r] = 0.5;
				jellyMo[p][r][0][0] = velocity;

				rigidY[p][r] = yCounter * ((ballHeight* 2) + (ballHeight*fullLrgY) + 0.1) + dropY;
				rigidX[p][r] = ((typeWriter - r) * ((ballHeight * 2)+ (ballHeight*fullLrgX) + ballHeight)) + dropX;

				rigidZ[p][r] = dropZ;
				
				frameNumber[r] = (int) rand() % levelLoadP.tailFrames.size();
				weight[frameNumber[r]] = 1;
				rigidIncrement[p][r] =  levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()/6; // less processing
				if(processGradient == 3){
					rigidIncrement[p][r] =  levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()/12; //bigger models may need lesser processing
				}
			

				if(divisionTime){
					for(int s = 0; s < 6; s++){
						splitCounter[r][s] = 0;
					}						
					splitSize[r] = 5;
					int used[3000];
					int usedCounter = 0;
					for(int s = 0; s < splitSize[r]; s++){
						smashXAngle[r][s] = 0;
						smashZAngle[r][s] = 0;
						smashNewXAngle[r][s] = smashXAngle[r][s];
						smashNewZAngle[r][s] = smashZAngle[r][s];
						smashX[r][s] = rigidX[p][r];
						smashZ[r][s] = rigidZ[p][r];
						smashY[r][s] = rigidY[p][r];
						smashFall[r][s] = 0.l;

						int startS = (int) rand() % levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size();
						int endS = startS+ (int) rand() % levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size();
						for(int sp = startS; sp < endS; sp++){
							if(sp < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()){
								bool isUsed = false;
								for(int i = 0; i < usedCounter; i++){
									if(sp == used[i]){
										isUsed = true;
										i = usedCounter;
									}
								}
								if(!isUsed){
									splitFrag[r][s][splitCounter[r][s]] = sp;
									splitCounter[r][s]++;
									used[usedCounter] = sp;
									usedCounter++;
								}
							}
						}						
					}
					smashXAngle[r][5] = 0;
					smashZAngle[r][5] = 0;
					smashNewXAngle[r][5] = 0;
					smashNewZAngle[r][5] = 0;
					smashX[r][5] = rigidX[p][r];
					smashY[r][5] = rigidY[p][r];
					smashZ[r][5] = rigidZ[p][r];
					smashFall[r][5] = 0.l;
					for(int s = 0; s < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size(); s++){
						bool isUsed = false;
						for(int frag = 0; frag < 6; frag++){
							for(int sp = 0; sp < splitCounter[r][frag]; sp++){
								if(splitFrag[r][frag][sp] == s){
									isUsed = true;
								}
							}
						}
						if(!isUsed){
							splitFrag[r][5][splitCounter[r][5]] = s;
							splitCounter[r][5]++;
						}
					}

				}
				if (r % rigidTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  rigidTop;
				}
				
				Mo[r] = 0.3;
			}
			float xIncrement  = 0;// = dropX; //15
			float yIncrement  = 0;//= dropY; //20
			float zIncrement  = 0;//= dropZ; //5
			
		}
		if(divisionTime){
			
			divisionEnd = divisionSplit + divisionSize;

			float fullLrgY = 0;
			float fullLrgX = 0;
			for(int i = 0; i < levelLoadP.tailFrames.size(); i++){
				if(levelLoadP.largestRY[i] > fullLrgY){
					fullLrgY = levelLoadP.largestRY[i];
				}
				if(levelLoadP.largestRX[i] > fullLrgX){
					fullLrgX = levelLoadP.largestRX[i];
				}
			}

			for(int r = divisionSplit; r < divisionEnd; r++){
				

				xrDirection[p][r] = false;
				zrDirection[p][r] = false;
				rigidXAngle[p][r] = 0;
				rigidZAngle[p][r] = 0;
				newRigidZAngle[p][r] = 0;
				newRigidXAngle[p][r] = 0;
				rigidFall[p][r] = 0.5;
				jellyMo[p][r][0][0] = velocity;
				

				rigidY[p][r] = yCounter * ((ballHeight* 2) + (ballHeight*fullLrgY) + 0.1) + dropY;
				rigidX[p][r] = ((typeWriter - r) * ((ballHeight * 2)+ (ballHeight*fullLrgX) + ballHeight)) + dropX;

				rigidZ[p][r] = dropZ;
				
				frameNumber[r] = (int) rand() % levelLoadP.tailFrames.size();
				rigidIncrement[p][r] =  levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()/10;
				if(processGradient == 3){
					rigidIncrement[p][r] =  levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()/12;
				}

				if(divisionTime){
					for(int s = 0; s < 6; s++){
						splitCounter[r][s] = 0;
					}						
					splitSize[r] = 5;
					int used[3000];
					int usedCounter = 0;
					for(int s = 0; s < splitSize[r]; s++){
						smashXAngle[r][s] = 0;
						smashZAngle[r][s] = 0;
						smashNewXAngle[r][s] = smashXAngle[r][s];
						smashNewZAngle[r][s] = smashZAngle[r][s];
						smashX[r][s] = rigidX[p][r];
						smashZ[r][s] = rigidZ[p][r];
						smashY[r][s] = rigidY[p][r];
						smashFall[r][s] = 0.l;
						//smashZ[r][s] = rigidZ[p][r];
						int startS = (int) rand() % levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size();
						int endS = startS+ (int) rand() % levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size();
						for(int sp = startS; sp < endS; sp++){
							if(sp < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size()){
								bool isUsed = false;
								for(int i = 0; i < usedCounter; i++){
									if(sp == used[i]){
										isUsed = true;
										i = usedCounter;
									}
								}
								if(!isUsed){
									splitFrag[r][s][splitCounter[r][s]] = sp;
									splitCounter[r][s]++;
									used[usedCounter] = sp;
									usedCounter++;
								}
							}
						}						
					}
					smashXAngle[r][5] = 0;
					smashZAngle[r][5] = 0;
					smashNewXAngle[r][5] = 0;
					smashNewZAngle[r][5] = 0;
					smashX[r][5] = rigidX[p][r];
					smashY[r][5] = rigidY[p][r];
					smashZ[r][5] = rigidZ[p][r];
					smashFall[r][5] = 0.l;
					for(int s = 0; s < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size(); s++){
						bool isUsed = false;
						for(int frag = 0; frag < 6; frag++){
							for(int sp = 0; sp < splitCounter[r][frag]; sp++){
								if(splitFrag[r][frag][sp] == s){
									isUsed = true;
								}
							}
						}
						if(!isUsed){
							splitFrag[r][5][splitCounter[r][5]] = s;
							splitCounter[r][5]++;
						}
					}

				}
				if (r % rigidTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  rigidTop;
				}
				
				Mo[r] = 0.3;
			}
			
			
		}
		
		float xIncrement  = 0;// = dropX; //15
			float yIncrement  = 0;//= dropY; //20
			float zIncrement  = 0;//= dropZ; //5
			
			for(int r = 1; r < divisionEnd; r++){
				ballCounter = 0;
				for(int i = 0; i < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size(); i++){
					
					//reset everything
					heatColour[r][i][0] = 0;
					heatColour[r][i][1] = 1;
					heatColour[r][i][2] = 0;
					
					Balls1[0][r][ballCounter][0] = 0;
					Balls1[0][r][ballCounter][1] = 0;
					Balls1[0][r][ballCounter][2] = 0;

					
					Balls1[1][r][ballCounter][0] = 0;
					Balls1[1][r][ballCounter][1] = 0;
					Balls1[1][r][ballCounter][2] = 0;

					
					Balls1[2][r][ballCounter][0] = 0;
					Balls1[2][r][ballCounter][1] = 0;
					Balls1[2][r][ballCounter][2] = 0;

					
					Balls1[3][r][ballCounter][0] = 0;
					Balls1[3][r][ballCounter][1] = 0;
					Balls1[3][r][ballCounter][2] = 0;

					
					oldBalls1[0][r][ballCounter][0] = 0;
					oldBalls1[0][r][ballCounter][1] = 0;
					oldBalls1[0][r][ballCounter][2] = 0;

					
					oldBalls1[1][r][ballCounter][0] = 0;
					oldBalls1[1][r][ballCounter][1] = 0;
					oldBalls1[1][r][ballCounter][2] = 0;

					
					oldBalls1[2][r][ballCounter][0] = 0;
					oldBalls1[2][r][ballCounter][1] = 0;
					oldBalls1[2][r][ballCounter][2] = 0;
					
					oldBalls1[3][r][ballCounter][0] = 0;
					oldBalls1[3][r][ballCounter][1] = 0;
					oldBalls1[3][r][ballCounter][2] = 0;
					
					//get the facesP, vertPexes and normalsP and put them into an array
					
					BallnormalsP[r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->x;
					BallnormalsP[r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->y;
					BallnormalsP[r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->z;
					
					
					
					Balls1[0][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->x + xIncrement;
					Balls1[0][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->y + yIncrement;
					Balls1[0][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->z +zIncrement;
					
					
					
					Balls1[1][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->x + xIncrement;
					Balls1[1][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->y +yIncrement;
					Balls1[1][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->z +zIncrement;
					
					Balls1[2][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->x + xIncrement;
					Balls1[2][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->y + yIncrement;
					Balls1[2][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->z + zIncrement;
					
					ballfacesP[r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0];
					ballfacesP[r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1];
					ballfacesP[r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2];

					
					//get the original for restoring tampering
					
					
					oldBalls1[0][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->x + xIncrement;
					oldBalls1[0][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->y +yIncrement;
					oldBalls1[0][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->z + zIncrement;
					
					oldBalls1[1][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->x +xIncrement;
					oldBalls1[1][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->y +yIncrement;
					oldBalls1[1][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->z + zIncrement;
					
					oldBalls1[2][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->x + xIncrement;
					oldBalls1[2][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->y +yIncrement;
					oldBalls1[2][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->z + zIncrement;
					
					
					
					if(levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->four){
						
						ballfacesP[r][ballCounter][3] = levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3];
						Balls1[3][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->x + xIncrement;
						Balls1[3][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->y +yIncrement;
						Balls1[3][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->z + zIncrement;
						
						oldBalls1[3][r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->x + xIncrement;
						oldBalls1[3][r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->y +yIncrement;
						oldBalls1[3][r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tavertP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->z + zIncrement;
					}

						ballCounter++;

				}
				ballJSize[p][r] = ballCounter;
				sortByX(r);
				
				
			

				cout << "size: " << ballCounter << endl;
				//pre process which facesP are connected to each other, so in realtime you only need to follow an array. 
				
				for (int v = 0; v < ballJSize[p][r]; v++) {
					
					for(int c = 0; c < 4; c++){
					int face1 = ballfacesP[r][v][c];
					int found = 0;
					for(int i = 0; i < ballJSize[p][r]; i++){
						

						if(i != v){

								if(ballfacesP[r][i][0] == face1){


										ouraFace[r][v][found][c] = i;
										ourafacesP[r][v][found][c] = 0;
										found++;
		
								}else if(ballfacesP[r][i][1] == face1){
	
									ouraFace[r][v][found][c] = i;
										ourafacesP[r][v][found][c] = 1;
										found++;
									//}
								}else if(ballfacesP[r][i][2] == face1){
	
									ouraFace[r][v][found][c] = i;
										ourafacesP[r][v][found][c] = 2;
										found++;
									//}
								}else if(ballfacesP[r][i][3] == face1){
	
								}

							}
					//	}
					}
					ouraFaceCounter[r][v][c] = found;

				}

					jellyPrio[p][r] = 0;
					jellyPrio[p][r] = 0;
					jellyPrio[p][r] = 0;
					jellyPrio[p][r] = 0;

				}
			}
		//}
	}else{
		float fullLrgY = 0;
			float fullLrgX = 0;
			for(int i = 0; i < levelLoadP.tailFrames.size(); i++){
				if(levelLoadP.largestRY[i] > fullLrgY){
					fullLrgY = levelLoadP.largestRY[i];
				}
				if(levelLoadP.largestRX[i] > fullLrgX){
					fullLrgX = levelLoadP.largestRX[i];
				}
			}
			for(int r = 0; r < jellyCounter; r++){
				if (r % rigidTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  rigidTop;
				}
			}
		for(int r = jellyCounter; r < jellyCounter+5; r++){
			jellyMo[p][r][0][0] = velocity;
				hitGround[r] = false;
				

				xrDirection[p][r] = false;
				mapCollisionCounter[r] = false;
				zrDirection[p][r] = false;
				rigidXAngle[p][r] = 0;
				rigidZAngle[p][r] = 0;
				rigidYAngle[p][r] = -90;
				newRigidZAngle[p][r] = 0;
				newRigidXAngle[p][r] = 0;
				rigidFall[p][r] = 0.5;
				rigidY[p][r] = yCounter * ((ballHeight* 2) + (ballHeight*fullLrgY) + 0.1) + dropY;
				rigidX[p][r] = ((typeWriter - r) * ((ballHeight * 2)+ (ballHeight*fullLrgX) + ballHeight)) + dropX;

				rigidZ[p][r] = dropZ;
				if (r % rigidTop == 0) {
					yCounter+= 1 ;
					typeWriter +=  rigidTop;
				}
				
		}
		jellyCounter+= 5;
		if(jellyCounter > jellySize){
			jellyCounter = 0;
		}
	}
	}
	
	//}
	//}

float physicsMain::getBalls(int l, int r, int i, int v){
	return Balls1[l][r][i][v];
}
int physicsMain::getJellySize(){
	return jellySize; 
}
int physicsMain::getballj(int r){
	return ballJSize[p][r];
}

float* physicsMain::getRigid(int r){
	float* rigids = (float*) malloc(sizeof(float)* 3);
	rigids[0] = rigidX[p][r];
	rigids[1] = rigidY[p][r];
	rigids[2] = rigidZ[p][r];
	return rigids;
}
float* physicsMain::getRotation(int r){
	float* rigidA = (float*) malloc(sizeof(float)*2);
	rigidA[0] = rigidXAngle[p][r];
	rigidA[1] = rigidZAngle[p][r];
	return rigidA;
}

void physicsMain::initModelPhysics(){
	for(int i = 0; i < ballSize; i++){
			ballColours[i] = i + 7 ;
			GLfloat light[] = {get_random(), get_random(), get_random(), 1};
			material(ballColours[i], light, light,light, emerald_shininess);
	}
	
	float yCounter = 1;
	float typeWriter = 0;
	
	yCounter = 1;
	typeWriter = 0;
		//cout << "helloworld" << endl;
	
	if(jellyTime || divisionTime){
		robotDefined = false;
		p = 0;
		while(!robotDefined){

		int ballCounter = 0;
		float fullX[20];
				float fullY[20];
			float fullLrgY = 0;
			float fullLrgX = 0;
			for(int i = 0; i < levelLoadP.robotP[p]->tailFrames.size(); i++){
				if(levelLoadP.largestRY[i] > fullLrgY){
					fullLrgY = levelLoadP.largestRY[i];
				}
				if(levelLoadP.largestRX[i] > fullLrgX){
					fullLrgX = levelLoadP.largestRX[i];
				}
			}
			if(robot){
				jellySize = robotSize;
			}
			if(ragdoll){
				ragAngleX = 0;
				ragAngleZ = 0;
				nragAngleX =0;
				nragAngleZ =0;
			}
			
				
			for(int r = 0; r < jellySize; r++){
				if(!robot){
					frameNumber[r] = (int) rand() % levelLoadP.robotP[p]->tailFrames.size();
				}else{
					frameNumber[r] = r;
				}
				rigidIncrement[p][r] = levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size() / 10;
				jellyPrio[p][r] = 0;

				xrDirection[p][r] = false;
				zrDirection[p][r] = false;
				rigidXAngle[p][r] = 0;
				rigidZAngle[p][r] = 0;
				newRigidZAngle[p][r] = 0;
				newRigidXAngle[p][r] = 0;
				rigidFall[p][r] = 0.5;

					float smallestX = 100;
				float largestX = -100;
				float smallestY = 100;
				float largestY = -100;
				float largestZ = -100;
				float smallestZ = 100;
				for(int i = levelLoadP.lowestPoint[r][1]; i < levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP.size(); i+= 1){
					for(int v = 0; v < 3; v++){

						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x > largestX){
							largestX = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x < smallestX){
							smallestX = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x;
						}
						
						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y > largestY){
							largestY = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y < smallestY){
							smallestY= levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y;
						}
						
						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z > largestZ){
							largestZ = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z < smallestZ){
							smallestZ = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z;
						}
					}
				
				}
				if(!robot){
					rigidY[p][r] = yCounter * ((ballHeight* 2) + (ballHeight*fullLrgY) + 0.1) + 10 ;
					rigidX[p][r] = ((typeWriter - r) * ((ballHeight * 2)+ (ballHeight*fullLrgX) + ballHeight));
				}else{
					rigidY[p][r] = (largestY * ballHeight) + 10;
					rigidX[p][r] = largestX * ballHeight;
					rigidZ[p][r] = largestZ * ballHeight;
				}
				

			}
			//cout << "come here" << endl;
			
			
			for(int r = 0; r < jellySize; r++){
				mapCollisionCounter[r] = false;
				float smallestX = 100;
				float largestX = -100;
				float smallestY = 100;
				float largestY = -100;
				float largestZ = -100;
				float smallestZ = 100;
				for(int i = levelLoadP.lowestPoint[r][1]; i < levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP.size(); i+= 1){
					for(int v = 0; v < 3; v++){
				//rigidIncrement[r] = 0.1 * levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size();
						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x > largestX){
							largestX = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x < smallestX){
							smallestX = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->x;
						}
						
						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y > largestY){
							largestY = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y < smallestY){
							smallestY= levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->y;
						}
						
						if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z > largestZ){
							largestZ = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z;
						}else if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z < smallestZ){
							smallestZ = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[v]-1]->z;
						}
					}
				
				}
				float xIncrement = 0;
				float yIncrement = 0;
				float zIncrement = 0;
				if(robot){
					xIncrement = -largestX + ((largestX - smallestX)/2); //15
					yIncrement = -largestY + ((largestY - smallestY)/2); //20
					zIncrement = -largestZ + ((largestZ - smallestZ)/2);

				}
				ballCounter = 0;

				for(int i = levelLoadP.lowestPoint[r][1]; i < levelLoadP.tailFrames[frameNumber[r]]->tafacesP.size(); i+= 1){
					Balls1[0][r][ballCounter][0] = 0;
					Balls1[0][r][ballCounter][1] = 0;
					Balls1[0][r][ballCounter][2] = 0;

					
					Balls1[1][r][ballCounter][0] = 0;
					Balls1[1][r][ballCounter][1] = 0;
					Balls1[1][r][ballCounter][2] = 0;

					
					Balls1[2][r][ballCounter][0] = 0;
					Balls1[2][r][ballCounter][1] = 0;
					Balls1[2][r][ballCounter][2] = 0;

					
					Balls1[3][r][ballCounter][0] = 0;
					Balls1[3][r][ballCounter][1] = 0;
					Balls1[3][r][ballCounter][2] = 0;

					
					oldBalls1[0][r][ballCounter][0] = 0;
					oldBalls1[0][r][ballCounter][1] = 0;
					oldBalls1[0][r][ballCounter][2] = 0;

					
					oldBalls1[1][r][ballCounter][0] = 0;
					oldBalls1[1][r][ballCounter][1] = 0;
					oldBalls1[1][r][ballCounter][2] = 0;

					
					oldBalls1[2][r][ballCounter][0] = 0;
					oldBalls1[2][r][ballCounter][1] = 0;
					oldBalls1[2][r][ballCounter][2] = 0;
					
					oldBalls1[3][r][ballCounter][0] = 0;
					oldBalls1[3][r][ballCounter][1] = 0;
					oldBalls1[3][r][ballCounter][2] = 0;

					
					BallnormalsP[r][ballCounter][0] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->x;
					BallnormalsP[r][ballCounter][1] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->y;
					BallnormalsP[r][ballCounter][2] = levelLoadP.tailFrames[frameNumber[r]]->tanormalsP[levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->facenum-1]->z;
					
					
					Balls1[0][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->x + xIncrement;
					Balls1[0][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->y + yIncrement;
					Balls1[0][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->z +zIncrement;
					
					Balls1[1][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->x + xIncrement;
					Balls1[1][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->y +yIncrement;
					Balls1[1][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->z +zIncrement;
					
					Balls1[2][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->x + xIncrement;
					Balls1[2][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->y + yIncrement;
					Balls1[2][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->z + zIncrement;
					
					ballfacesP[r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0];
					ballfacesP[r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1];
					ballfacesP[r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2];
					

					oldBalls1[0][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->x + xIncrement;
					oldBalls1[0][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->y +yIncrement;
					oldBalls1[0][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[0]-1]->z + zIncrement;
					
					oldBalls1[1][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->x +xIncrement;
					oldBalls1[1][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->y +yIncrement;
					oldBalls1[1][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[1]-1]->z + zIncrement;
					
					oldBalls1[2][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->x + xIncrement;
					oldBalls1[2][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->y +yIncrement;
					oldBalls1[2][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[2]-1]->z + zIncrement;
					
					
					
					if(levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->four){
						
						ballfacesP[r][ballCounter][3] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3];
						Balls1[3][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->x + xIncrement;
						Balls1[3][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->y +yIncrement;
						Balls1[3][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->z + zIncrement;
						
						oldBalls1[3][r][ballCounter][0] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->x + xIncrement;
						oldBalls1[3][r][ballCounter][1] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->y +yIncrement;
						oldBalls1[3][r][ballCounter][2] = levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tavertP[levelLoadP.robotP[p]->tailFrames[frameNumber[r]]->tafacesP[i]->facesP[3]-1]->z + zIncrement;
					}

						ballCounter++;

				}

				ballJSize[p][r] = ballCounter;
				for (int v = 0; v < ballJSize[p][r]; v++) {

					jellyMo[p][r][v][0] = velocity;
					jellyMo[p][r][v][1] = velocity;
					jellyMo[p][r][v][2] = velocity;
					jellyMo[p][r][v][3] = velocity;
					

				}
			}
			//}
				if(robot){
					if(p < 6){
						p++;
					}else{
						robotDefined = true;
						p = 0;
					}
				}else{
					robotDefined = true;
				}
			}
		//}
	}
	
	//}
}


void physicsMain::processEfficient(){ // low reaction models
	levelLoadP.clearModels();
	levelLoadP.appendReactionObject("Objects/lowReaction.obj");
}
void physicsMain::processNeutral(){ // 35kb models
	levelLoadP.clearModels();
	//levelLoadP.appendReactionObject("Objects/reaction1.obj");
	levelLoadP.appendReactionObject("Objects/reaction2.obj");
	levelLoadP.appendReactionObject("Objects/reaction3.obj");
	levelLoadP.appendReactionObject("Objects/reaction4.obj");
	levelLoadP.appendReactionObject("Objects/reaction5.obj");
	levelLoadP.appendReactionObject("Objects/reaction3.obj");

}
int physicsMain::getProcess(){ // get the process for insight.
	return processGradient;
}
void physicsMain::loadHand(){ //get the hand model and set the spawn of it
	levelLoadP.loadHand("Objects/hand.obj");
	handTime = true;
	//handX = 9;
	//handY = 2;
	//handZ = 0;
	handCounter = 0;
			for(int i =0; i < levelLoadP.hfacesP.size(); i+= 5){
				handRX[handCounter] = levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->x;
				handRY[handCounter] = levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->y;
				handRZ[handCounter] = levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->z;
				
				handCounter++;

				
			}
}
void physicsMain::setHands(int counter, float x, float y, float z){
	//for(int i = 0; i < size; i++){
		handX[counter] = x;
		handY[counter] = y;
		handZ[counter] = z;
//	}
	//handCount = size;
}
void physicsMain::setHandCounter(int count){
	handCount = count;
}

void physicsMain::moveHandX(float value){ //move hand
	handZ[0] += value;
}
void physicsMain::moveHandY(float value){
	handY[0] += value;
}
bool physicsMain::getHand(){ //is the hand spawned?
	return handTime;
}
void physicsMain::LoadMap(bool show, const char* filename){
	levelLoadP.loadCollisionObject(filename);
	setObsticleCollisions(true);
	customObject = show;
}
void physicsMain::LoadMapWithSkewArray(float x, float y, float z, int index, float size ){
			obsticleSize[index] = size;
			obsticleX[index] = x;
			obsticleY[index] = y;
			obsticleZ[index] = z;
			
			obsticleType[index] = 'r';
			
			
		
		//	cout << obsticleX[index] << endl;
		//	cout << obsticleY[index] << endl;
		//	cout << obsticleZ[index] << endl;
		//	cout << obsticleSize[index] << endl;
	
}
void physicsMain::SetObsticleLength(int max){
	obsticleCounter = max;
	
	cout <<"obsticle counter" <<obsticleCounter << endl;
	
}
void physicsMain::LoadBodies(char* folder){
	//for(int i = 0; i < 4; i++){

		levelLoadP.appendReactionObject("Objects/coinDrop/reaction1.obj");
		levelLoadP.appendReactionObject("Objects/coinDrop/reaction2.obj");
		levelLoadP.appendReactionObject("Objects/coinDrop/reaction3.obj");
		//levelLoadP.appendReactionObject("Objects/coinDrop/reaction4.obj");
		//levelLoadP.appendReactionObject("Objects/coinDrop/reaction5.obj");
	//}
}
void physicsMain::process(int gradient){ //break up different testing environments
	loadHand();
	if(gradient == 0){
		processGradient = gradient;
		levelLoadP.clearModels();
		levelLoadP.appendReactionObject("Objects/Marble/marble.obj");
		levelLoadP.loadCollisionObject("Objects/Marble/galton.obj");
		velocity = 0.4;
		//statTime = true;
		setObsticleCollisions(true);
		//cubeTime = true;
	}else if(gradient == 5){
		levelLoadP.clearModels();
		levelLoadP.loadCollisionObject("Objects/show/table.obj");
		levelLoadP.appendReactionObject("Objects/show/bottle.obj");
		levelLoadP.appendReactionObject("Objects/show/can.obj");
		setScale(2);
		velocity = 0.05;
		setRigidSplit(8);
		setAmount(8);
		setObsticleCollisions(true);
	}else if(gradient == 1){
		processGradient = gradient;
		marbleTime = true;
		levelLoadP.loadCollisionObject("Objects/Marble/roll.obj");
		marbleSize = 4;
		setObsticleCollisions(true);
		levelLoadP.clearModels();

		
	}else if(gradient == 2){
		processGradient = gradient;

		processNeutral();
		
		//statTime = true;
		randomMap();
	}else if(gradient == 3){
		processGradient = gradient;
		levelLoadP.clearModels();

		levelLoadP.appendReactionObject("Objects/efficient/reaction1.obj");
		levelLoadP.appendReactionObject("Objects/efficient/reaction2.obj");
		levelLoadP.appendReactionObject("Objects/efficient/reaction3.obj");
		randomMap();

	}else if(gradient == 4){
		processGradient = gradient;
		levelLoadP.clearModels();
		processNeutral();
		levelLoadP.loadCollisionObject("Objects/jokes.obj");
		setCogs(true);
		initMarble();
		setObsticleCollisions(true);
		setScale(1.2);
		setCoords(9, 20, 5.5);
		setFabricCoords(-13, 15, -2);
		setDominoCoords(12,0,0);

		setSoft();

		setFabricTest();
		divisionTime = true;
		divisionSize = 10;
		initPhysics(true);
		for(int i = 0; i < jellySize; i++){

			float rand = get_random();
			jellyMo[p][i][0][0] = 1.2;
			velocity = 0.7;
			if(rand > 0.5){
				divider[i] = 10;
				jellyMo[p][i][0][0] = 0.3;
			}else{
				divider[i] = 2;
				
			}
			
		}
		
		
		
		resetDomino();
		initDomino(30, true);
		initDomino(-60, true);
		initDomino(0, false);
		setDominoGap(53, 0, 0);
		initDomino(15, true);
		initDomino(0, false);
		initDomino(-45, true);
		initDomino(-45, true);
		
		setDominoGap(-60, 0, -30);
		initDomino(90, true);

		resetDomino();
		initDomino(30, true);
		initDomino(-60, true);
		initDomino(0, false);
		setDominoGap(53, 0, 0);
		initDomino(15, true);
		initDomino(0, false);
		initDomino(-45, true);
		initDomino(-45, true);
		
		setDominoGap(-60, 0, -30);
		initDomino(90, true);

		kettleTime = true;

	}
	if(kettleTime){
		kettleX = 56;
		kettleY = -14;
		kettleZ = 0;
		
		kettleSX = kettleX + 4;
		kettleSY = kettleY + 8;
		kettleSZ = kettleZ;
		for(int i = 0; i < 200; i++){
			kettleScale[i] = 0.2;
		}
		
		
		levelLoadP.loadKettle("Objects/kettle.obj");
		levelLoadP.loadSmoke("Objects/cube.obj");
		
		//setCogs(true);
	}
	
}
void physicsMain::setDominoCoords(float x, float y, float z){
	dominoSX = x;
	dominoSY = y;
	dominoSZ = z;
}
void physicsMain::setSplit(int value){
	fabricTop = value;
}
void physicsMain::setCubeTime(bool setter){
	cubeTime = setter;
	if(cubeTime){
		levelLoadP.clearModels();
		levelLoadP.appendReactionObject("Objects/cube.obj");
		setAmount(jellySize*2);
		//flatSurface();
		
	}else{
		
		process(processGradient);
		setAmount(jellySize/2);
	}
}
void physicsMain::flatSurface(){
	levelLoadP.loadCollisionObject("Objects/flatTrack.obj");
	setObsticleCollisions(true);
}
void physicsMain::setIce(bool setter){ // ice configuration
	iceMode = setter;
	if(iceMode){
		slip = 1;
		velocity = 1;
	}else{
		slip = 1;
	}
}
void physicsMain::setSticky(bool stickEr){
	stickIt = stickEr;
	if(stickIt){
		stick = 0;
		sticky = 5;
		velocity= 0.3;
	}else{
		stick = 180;
		sticky = 1;

	}
}
void physicsMain::setAmount(int amount){
	jellySize = amount;
	ballSize = amount;
}
void physicsMain::setBreak(){ //initialise division mode
	if(fabricTime){
		setAmount(30);
		setRigidSplit(5);
	}
	if(meltingTime){
		setAmount(30);
	}
	for(int i = 0; i < jellySize; i++){
		divider[i] = 1;
	}

	dominoTime = false;
	ropeTime = false;
	meltingTime = false;
	jellyTime = false;
	robotFalling = true;
	divisionTime = true;
	divisionSize = jellySize;
	fabricTime = false;
	setSticky(false);
	setIce(false);
}
void physicsMain::setFalling(){
	robotFalling = true;
}
void physicsMain::setMelting(){
	setHard();
	setAmount(10);
	meltingTime = true;
	for(int r = 0; r < jellySize; r++){
		for(int i = 0; i < 2000; i++){
			collidedM[r][i] = false;
		}
	}
}
void physicsMain::setHard(){ // initializes hard bodies

	for(int i = 0; i < jellySize; i++){
		getStats[i] = false;
	}
	if(fabricTime){
		setAmount(30);
		setRigidSplit(5);
	}
	if(processGradient == 0){
		bounce = 0;
	}else{
		bounce = 5;
	}
	if(meltingTime){
		setAmount(30);
	}
	for(int i = 0; i < jellySize; i++){
		divider[i] = 1;
	}

	//dominoTime = false;
	ropeTime = false;
	meltingTime = false;
	jellyTime = true;
		rigidBody = false;
		robotFalling = true;
		cubeTime = false;
	divisionTime = false;
	fabricTime = false;
	ballPond = false;
	setSticky(false);
	setIce(false);
}
void physicsMain::setSoftGradient(float div){
	for(int i = 0; i < jellySize; i++){
		if(div > 0){
			divider[i] = div;
			if((2/div) >= 0){
				bounce = 2/div;
			}else{
				bounce = 0;
			}
		}
	}
}

float physicsMain::getGradient(){
	return divider[0];
}
bool physicsMain::isDomino(){
	return dominoTime;
}
void physicsMain::runDomino(){
	//for(int i = 0; i < ballSize; i++){
		dHitting[0] = true;
	//}
}
void physicsMain::setSoft(){ // initializes soft bodies
	for(int i = 0; i < jellySize; i++){
		getStats[i] = false;
	}

	if(fabricTime){
		setAmount(30);
		setRigidSplit(5);
	}
	if(meltingTime){
		setAmount(30);
	}
	bounce = 0;
	for(int i = 0; i < jellySize; i++){
		divider[i] = 15;
	}
	if(processGradient == 3){
		for(int i = 0; i < jellySize; i++){
			divider[i] = 15;
		}
	}
	stick = 180;
	jellyTime = true;
	meltingTime = false;
		rigidBody = false;
		robotFalling = true;
	robotFalling = true;
	divisionTime = false;
	fabricTime = false;
	dominoTime = false;
	ropeTime = false;
	ballPond = false;
	setSticky(false);
	setIce(false);
}
void physicsMain::setVelocity(float vel){
	velocity = vel;
}
float physicsMain::getVelocity(){
	return velocity;
}

void physicsMain::setCoords(float x, float y, float z){
	dropX = x;
	dropY = y;
	dropZ = z;
}

void physicsMain::setFabricCoords(float x, float y, float z){
	fabricX = x;
	fabricY = y;
	fabricZ = z;
}
void physicsMain::setFabric(){ // intializes fabric mode
	for(int i = 0; i < jellySize; i++){
		divider[i] = 1;
	}
	
	jellyTime = false;
	robotFalling = false;
	divisionTime = false;
	dominoTime = false;
	ropeTime = false;
	horizontal = false;
	ballPond = false;
	fabricTime = true;
	fabricFinished = false;
	fabricTest = false;
	setAmount(0);
	setSplit(10);
	setSticky(false);
	setIce(false);
}
bool physicsMain::isModel(){
	return robot;
}
void physicsMain::dropModel(){
	robotFalling = true;
}
void physicsMain::setCogReaction(bool set){
	cogReaction = set;
}

void physicsMain::setCogs(bool set){ // creates cogs
	cogs = set;
	if(cogs == true){
		if(processGradient == 4){
			levelLoadP.loadCogLocation("Objects/MovingObsticles/cogLocation.obj");
		}else{
			levelLoadP.loadCogLocation("Objects/MovingObsticles/cogLocation2.obj");
		}
		levelLoadP.loadCog("Objects/MovingObsticles/cog.obj");
		if(levelLoadP.pafacesP.size() %6 ==0){
			cogSize = levelLoadP.pafacesP.size()/6;
			for(int i = 0; i < cogSize; i++){
				cogX[i] =  levelLoadP.pavertP[levelLoadP.pafacesP[i*6 + 1]->facesP[1]-1]->x;
				cogZ[i] =  levelLoadP.pavertP[levelLoadP.pafacesP[i*6 + 1]->facesP[1]-1]->z;
				cogY[i] =  levelLoadP.pavertP[levelLoadP.pafacesP[i*6 + 1]->facesP[1]-1]->y;
			}
		}
		setObsticleCollisions(true);
	}
}
void physicsMain::setScale(float amount){
	if(amount > 0){
		ballHeight = amount;
	}
}
float physicsMain::getScale(){
	return ballHeight;
}
void physicsMain::setRobot(){
	robot = true;		
	robotSkew = 0.3;
	ballHeight = 2;
	levelLoadP.clearModels();
	robotSize = 0;


	for(int i = 1; i < 10; i++){
		std::string rM = "Objects/Robot/robot";
		rM += std::to_string(i);
		rM += ".obj";
		char* robotA = (char*) rM.c_str();
		levelLoadP.clearModels();
		robotSize = levelLoadP.loadRobot(robotA);					
	}
	ragdoll = false;
	fabricTime = false;
	robotFalling = false;
	divisionTime = false;
	jellyTime = true;
		
}
void physicsMain::setRag(){ // attempt at ragdoll mode
	robot = true;
	ragdoll = true;	
	robotSkew = 0.3;
	ballHeight = 2;
	levelLoadP.clearModels();
	robotSize = 0;


	for(int i = 1; i < 10; i++){
		std::string rM = "Objects/Robot/robot";
		rM += std::to_string(i);
		rM += ".obj";
		char* robotA = (char*) rM.c_str();
		levelLoadP.clearModels();
		robotSize = levelLoadP.loadRobot(robotA);					
	}
	fabricTime = false;
	robotFalling = false;
	divisionTime = false;
	jellyTime = true;
		
}
void physicsMain::bubbleSortObsticle(){ // obsticle sorted by the z axis
	int i, j;  
	int n = obsticleCounter;
    for (i = 0; i < n-1; i++){      
		  
		// Last i elements are already in place  
		for (j = 0; j < n-i-1; j++) { 
			if (obsticleZ[j] > obsticleZ[j+1]) {
				swap(&obsticleX[j], &obsticleX[j+1]);
				swap(&obsticleY[j], &obsticleY[j+1]);
				swap(&obsticleZ[j], &obsticleZ[j+1]);
				swap(&obsticleSize[j], &obsticleSize[j+1]);
			}
		}
	}
}
void physicsMain::setObsticleCollisions(bool flat){ // creates the points for the collisions /3
	if(!flat){
		levelLoadP.loadCollisionObject("Objects/collisionObject.obj");
	}
	customObject = true;
	obsticleCounter = 0;
	int increase = 3;

	for(int i = 0; i < levelLoadP.spfacesP.size(); i+= increase){
			obsticleSize[obsticleCounter] = (levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->y - levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->y)+0.5;
			obsticleX[obsticleCounter] = levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->x;
			obsticleY[obsticleCounter] = levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->y - (obsticleSize[obsticleCounter]);
			obsticleZ[obsticleCounter] = levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->z;
			
			obsticleType[obsticleCounter] = 'r';
			obsticleCounter++;
	}
	bubbleSortObsticle();
	if(cogs){

			increase = increase +3;

		cogFSize = 0;
		for(int c = 0; c < cogSize; c++){
			
			cogLength[c] = obsticleCounter + cogFSize;
			for(int i =0; i < levelLoadP.cafacesP.size(); i+= increase){
				obsticleSize[obsticleCounter + cogFSize] = levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->y - levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->y;
				if(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->x - levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->x > obsticleSize[obsticleCounter + cogFSize]){
					obsticleSize[obsticleCounter+ cogFSize] = levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->x - levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->x;
				}
				obsticleX[obsticleCounter+ cogFSize] = levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->x;
				obsticleY[obsticleCounter+ cogFSize] = levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->y;
				obsticleZ[obsticleCounter+ cogFSize] = levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->z;
					
				cogFSize++;
			}
		}
		cogLength[cogSize] = obsticleCounter + cogFSize;
	}
	//cout << "setting obsticles" << endl;
}



bool physicsMain::collision(float p1x, float p1y, float r1, float p2x, float p2y,  float r2) { //circle collision to deal with curves and concave shapes
    float a;
    float x;
    float y;
    a = r1 + r2;
    x = p1x - p2x;
    y = p1y - p2y;
    if (a > sqrt((x * x) + (y * y))) {
        return true;
    } else {
        return false;
    }
}

void physicsMain::drawScene(){ //using opengl to print the triangles or quads.

					if(marbleTime){
						for(int i = 0; i < marbleSize; i++){
							glPushMatrix();
							glTranslatef(marble[i][0], marble[i][1], marble[i][2]);
							gluQuadricDrawStyle(sphere, GLU_FILL);

							gluQuadricTexture(sphere, GL_TRUE);
							gluQuadricNormals(sphere, GLU_SMOOTH);
							gluSphere(sphere, marbleDimensions, 64, 32); //glu sphere is a internal object
						
							glPopMatrix();
						}
						
						
					}
					if(ropeTime){
						for(int i = 0; i < ropeCounter * (ropeSize); i++){
							
							if(i % ropeCounter ==0 || i == 0){
								glPushMatrix();
								glScalef(ropeDimensions, ropeDimensions, ropeDimensions);
								glTranslatef(ropeX[i], ropeY[i], ropeZ[i]);
								glRotatef(ropeAngle[i], 0, 0, 1);
								for(int i=0;i< levelLoadP.refacesP.size();i++){	
									//if((i+1) % 6 == 0){	
											if(levelLoadP.refacesP[i]->four){	//if it's a quad draw a quad

													glBegin(GL_QUADS);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->x,levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->y,levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->z);
														glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->z);
													glEnd();
												}else{
													
	
													glBegin(GL_TRIANGLES);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->x,levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->y,levelLoadP.renormalsP[levelLoadP.refacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[2]-1]->z);
														//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->x,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->y,levelLoadP.revertP[levelLoadP.refacesP[i]->facesP[3]-1]->z);
													glEnd();	
			
												}
										}
									glPopMatrix();
							}else{
								glPushMatrix();
								glScalef(ropeDimensions, ropeDimensions, ropeDimensions);
								glTranslatef(ropeX[i], ropeY[i], ropeZ[i]);
								glRotatef(ropeAngle[i], 0, 0, 1);
								for(int i=0;i< levelLoadP.rfacesP.size();i++){	
									//if((i+1) % 6 == 0){	
											if(levelLoadP.rfacesP[i]->four){	//if it's a quad draw a quad
	
													glBegin(GL_QUADS);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->x,levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->y,levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->z);
														glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->z);
													glEnd();
												}else{

													glBegin(GL_TRIANGLES);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->x,levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->y,levelLoadP.rnormalsP[levelLoadP.rfacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[2]-1]->z);
														//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->x,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->y,levelLoadP.rvertP[levelLoadP.rfacesP[i]->facesP[3]-1]->z);
													glEnd();	
			
												}
										}
									glPopMatrix();
								
								}
							}
					
					}
					if(handTime){
						glPushMatrix();
							glTranslatef(handX[0], handY[0], handZ[0]);
							for(int i=0;i< levelLoadP.hfacesP.size();i++){	
								//if((i+1) % 6 == 0){	
										if(levelLoadP.hfacesP[i]->four){	//if it's a quad draw a quad

												glBegin(GL_QUADS);
													//basihlly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 behuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->x,levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->y,levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->z);
													glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->z);
												glEnd();
											}else{
												
	
												glBegin(GL_TRIANGLES);
													//basihlly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 behuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->x,levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->y,levelLoadP.hnormalsP[levelLoadP.hfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[2]-1]->z);
													//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->x,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->y,levelLoadP.hvertP[levelLoadP.hfacesP[i]->facesP[3]-1]->z);
												glEnd();	
	
											}
									}
							glPopMatrix();
					}
					if(cogs){
						for(int i =0;i < cogSize;i++){
							glPushMatrix();
							glTranslatef(cogX[i], cogY[i], cogZ[i]);
							glRotatef(cogAngle[i], 0, 0, 1);
							glTranslatef(-cogX[i], -cogY[i], -cogZ[i]);
							glTranslatef(cogX[i], cogY[i], cogZ[i]);
							for(int i=0;i< levelLoadP.cafacesP.size();i++){	
								//if((i+1) % 6 == 0){	
										if(levelLoadP.cafacesP[i]->four){	//if it's a quad draw a quad
	
												glBegin(GL_QUADS);
													//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 because the index start from 0 in C++
													
													glNormal3f(levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->x,levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->y,levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->z);
													glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->z);
												glEnd();
											}else{
			
												glBegin(GL_TRIANGLES);
													//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 because the index start from 0 in C++
													
													glNormal3f(levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->x,levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->y,levelLoadP.canormalsP[levelLoadP.cafacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[2]-1]->z);
													//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->x,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->y,levelLoadP.cavertP[levelLoadP.cafacesP[i]->facesP[3]-1]->z);
												glEnd();	

											}
									}
								glPopMatrix();
						}
					}
					if(kettleTime && kettleBoil){
						
						for(int c = 0; c < 200; c++){
							glPushMatrix();
							glCallList(ballColours[c]);
							glTranslatef(kettleSX, kettleSY, kettleSZ);
							glTranslatef(Balls1[1][0][c][0],Balls1[1][0][c][1], Balls1[1][0][c][2]);
							glScalef(kettleScale[c], kettleScale[c], kettleScale[c]);
							for(int i=0;i< levelLoadP.smfacesP.size();i++){	
								//if((i+1) % 6 == 0){	
										if(levelLoadP.smfacesP[i]->four){	//if it's a quad draw a quad
			
												glBegin(GL_QUADS);
													//basismlly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 besmuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->x,levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->y,levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->z);
													glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->z);
												glEnd();
											}else{
		
												glBegin(GL_TRIANGLES);
													//basismlly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 besmuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->x,levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->y,levelLoadP.smnormalsP[levelLoadP.smfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[2]-1]->z);
													//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->x,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->y,levelLoadP.smvertP[levelLoadP.smfacesP[i]->facesP[3]-1]->z);
												glEnd();	

											}
									}
								glPopMatrix();
						}
					}
					if(kettleTime){
						glPushMatrix();
						glTranslatef(kettleX, kettleY, kettleZ);
						for(int i=0;i< levelLoadP.kfacesP.size();i++){	
								//if((i+1) % 6 == 0){	
										if(levelLoadP.kfacesP[i]->four){	//if it's a quad draw a quad
											//if((i+1) % 6 != 0){
											//	std::cout << "here 1" << std::endl;
												glBegin(GL_QUADS);
													//basiklly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 bekuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->x,levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->y,levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->z);
													glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->z);
												glEnd();
											}else{

												glBegin(GL_TRIANGLES);
													//basiklly all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 bekuse the index start from 0 in C++
													
													glNormal3f(levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->x,levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->y,levelLoadP.knormalsP[levelLoadP.kfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[2]-1]->z);
													//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->x,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->y,levelLoadP.kvertP[levelLoadP.kfacesP[i]->facesP[3]-1]->z);
												glEnd();	
	
											}
									}
						glPopMatrix();
						
					}
					
					if(customObject){
						for(int i=0;i< levelLoadP.spfacesP.size();i++){	

										if(levelLoadP.spfacesP[i]->four){	//if it's a quad draw a quad

												glBegin(GL_QUADS);
													//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 because the index start from 0 in C++
													
													glNormal3f(levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->x,levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->y,levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->z);
													glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->z);
												glEnd();
											}else{
												

												glBegin(GL_TRIANGLES);
													//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
													//I subtract 1 because the index start from 0 in C++
													
													glNormal3f(levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->x,levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->y,levelLoadP.spnormalsP[levelLoadP.spfacesP[i]->facenum-1]->z);
													//draw the facesP
													glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[0]-1]->z);
													glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[1]-1]->z);
													glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[2]-1]->z);
													//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->x,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->y,levelLoadP.spvertP[levelLoadP.spfacesP[i]->facesP[3]-1]->z);
												glEnd();	
	
											}
								//	}
						}
					}
					
				/*	for(int o = 0; o < stoneSize2; o++){
						for(int i=0;i< obsticleCounter;i++){	

										glPushMatrix();

													 
														glTranslatef(obsticleX[i], obsticleY[i] + stoneY2[o], obsticleZ[i] + stoneX2[o]);
														gluQuadricDrawStyle(sphere, GLU_FILL);

														gluQuadricTexture(sphere, GL_TRUE);
														gluQuadricNormals(sphere, GLU_SMOOTH);
														gluSphere(sphere, 1, 2,2); //glu sphere is a internal object
													//glTexCoord2f(1.0, 0.0); obsticleY[i];

											glPopMatrix();
								//	}
						}
					}*/
					/*
					for(int o = 0; o < grassSize2; o++){
						for(int i=0;i< obsticleCounter;i++){	

										glPushMatrix();

													 
														glTranslatef(obsticleX[i], obsticleY[i] + grassY2[o], obsticleZ[i] + grassX2[o]);
														gluQuadricDrawStyle(sphere, GLU_FILL);

														gluQuadricTexture(sphere, GL_TRUE);
														gluQuadricNormals(sphere, GLU_SMOOTH);
														gluSphere(sphere, 1, 2,2); //glu sphere is a internal object
													//glTexCoord2f(1.0, 0.0); obsticleY[i];

											glPopMatrix();
								//	}
						}
					}
					for(int o = 0; o < dirtSize2; o++){
						for(int i=0;i< obsticleCounter;i++){	

										glPushMatrix();

													 
														glTranslatef(obsticleX[i], obsticleY[i] + dirtY2[o], obsticleZ[i] + dirtX2[o]);
														gluQuadricDrawStyle(sphere, GLU_FILL);

														gluQuadricTexture(sphere, GL_TRUE);
														gluQuadricNormals(sphere, GLU_SMOOTH);
														gluSphere(sphere, 1, 2,2); //glu sphere is a internal object
													//glTexCoord2f(1.0, 0.0); obsticleY[i];

											glPopMatrix();
								//	}
						}
					}
					for(int o = 0; o < woodSize2; o++){
						for(int i=0;i< obsticleCounter;i++){	

										glPushMatrix();

													 
														glTranslatef(obsticleX[i], obsticleY[i] + woodY2[o], obsticleZ[i] + woodX2[o]);
														gluQuadricDrawStyle(sphere, GLU_FILL);

														gluQuadricTexture(sphere, GL_TRUE);
														gluQuadricNormals(sphere, GLU_SMOOTH);
														gluSphere(sphere, 1, 2,2); //glu sphere is a internal object
													//glTexCoord2f(1.0, 0.0); obsticleY[i];

											glPopMatrix();
								//	}
						}
					}
					if(dominoTime){
						for(int v = 0; v < dominoCount; v++){
							glCallList(ballColours[v]);
							glPushMatrix();
							glTranslatef(dominoX[v], dominoY[v], dominoZ[v]);
							glTranslatef(0, -dominoHeight, 0);

							glRotatef(-(dominoAngleX[v]), 0, 1, 0);
							glRotatef(dominoAngleY[v], 0, 0, 1);

							glTranslatef(0, dominoHeight, 0);

							glTranslatef(-dominoX[v], -dominoY[v], -dominoZ[v]);
							glTranslatef(dominoX[v], dominoY[v], dominoZ[v]);
							
							for(int i=0;i< levelLoadP.dfacesP.size();i++){	

											if(levelLoadP.dfacesP[i]->four){	//if it's a quad draw a quad

													glBegin(GL_QUADS);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->x,levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->y,levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->z);
														glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->z);
													glEnd();
												}else{
													
	
													glBegin(GL_TRIANGLES);
														//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
														//I subtract 1 because the index start from 0 in C++
														
														glNormal3f(levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->x,levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->y,levelLoadP.dnormalsP[levelLoadP.dfacesP[i]->facenum-1]->z);
														//draw the facesP
														glTexCoord2f(1.0, 1.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[0]-1]->z);
														glTexCoord2f(1.0, 0.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[1]-1]->z);
														glTexCoord2f(0.0, 0.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[2]-1]->z);
														//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->x,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->y,levelLoadP.dvertP[levelLoadP.dfacesP[i]->facesP[3]-1]->z);
													glEnd();	

												}
									//	}
							}
							glPopMatrix();
						}
						
					}
			//	}
			
			if(divisionTime){
				
				for(int r = divisionSplit; r < divisionEnd; r++){
							
							
							glCallList(ballColours[r]); //colour

							
					for(int frags = 0; frags < splitSize[r]+1; frags++){ //fragments
						glPushMatrix();

						glTranslatef(smashX[r][frags], (smashY[r][frags]), smashZ[r][frags]);
						glRotatef(smashXAngle[r][frags], 0, 0, 1);
						glRotatef(smashZAngle[r][frags], 1, 0, 0);
						
						glScalef(ballHeight, ballHeight, ballHeight);
						for(int sp =0; sp < splitCounter[r][frags]; sp++){ //points in the certain fragment

									
									if(levelLoadP.tailFrames[frameNumber[r]]->tafacesP[splitFrag[r][frags][sp]]->four){	//if it's a quad draw a quad
										glBegin(GL_QUADS);
											glNormal3f(BallnormalsP[r][splitFrag[r][frags][sp]][0],BallnormalsP[r][splitFrag[r][frags][sp]][1], BallnormalsP[r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[0][r][splitFrag[r][frags][sp]][0], Balls1[0][r][splitFrag[r][frags][sp]][1], Balls1[0][r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[1][r][splitFrag[r][frags][sp]][0], Balls1[1][r][splitFrag[r][frags][sp]][1], Balls1[1][r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[2][r][splitFrag[r][frags][sp]][0], Balls1[2][r][splitFrag[r][frags][sp]][1], Balls1[2][r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[3][r][splitFrag[r][frags][sp]][0], Balls1[3][r][splitFrag[r][frags][sp]][1], Balls1[3][r][splitFrag[r][frags][sp]][2]);
										glEnd();
										
									}else{
										glBegin(GL_TRIANGLES);
											glNormal3f(BallnormalsP[r][splitFrag[r][frags][sp]][0],BallnormalsP[r][splitFrag[r][frags][sp]][1], BallnormalsP[r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[0][r][splitFrag[r][frags][sp]][0], Balls1[0][r][splitFrag[r][frags][sp]][1], Balls1[0][r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[1][r][splitFrag[r][frags][sp]][0], Balls1[1][r][splitFrag[r][frags][sp]][1], Balls1[1][r][splitFrag[r][frags][sp]][2]);
											glVertex3f(Balls1[2][r][splitFrag[r][frags][sp]][0], Balls1[2][r][splitFrag[r][frags][sp]][1], Balls1[2][r][splitFrag[r][frags][sp]][2]);
										glEnd();
										
									
									}

					}
					glPopMatrix();
				}
				}
			}
			if(fluidTime){
				int start = 0;
				for(int r = start; r < fluidSize; r++){
							
							glCallList(ballColours[r]);
							
							glPushMatrix();
							glTranslatef(Balls1[0][0][r][0], (Balls1[0][0][r][1]), Balls1[0][0][r][2]); //using part of a defined array
							
							gluQuadricDrawStyle(sphere, GLU_FILL);

							gluQuadricTexture(sphere, GL_TRUE);
							gluQuadricNormals(sphere, GLU_SMOOTH);
							gluSphere(sphere, ballHeight, 8, 4); //low cost sphere
							glPopMatrix();
							
				}
				
			if(jellyTime || rigidBody){
						int start = 1;
						if(robot){
							start = 0;
						}
						for(int r = start; r < jellySize; r++){
							
							
							
							glPushMatrix();
							glTranslatef(rigidX[p][r], (rigidY[p][r]), rigidZ[p][r]);
							
	
							
							glRotatef(rigidXAngle[p][r], 0, 0, 1);
							glRotatef(rigidZAngle[p][r], 1, 0, 0);

	
							glScalef(ballHeight, ballHeight, ballHeight);
							glColor4f(ballColor[r][0], ballColor[r][1], ballColor[r][2], 1);
	
							for(int i = 0; i < ballJSize[p][r]; i++){
								
								if(heatMap){
										int heat = 0;
										GLfloat light[] = {heatColour[r][i][0], heatColour[r][i][2], heatColour[r][i][1], 1};
										material(heat, light, light,light, emerald_shininess);
										glCallList(heat);
								}

									if(levelLoadP.tailFrames[frameNumber[r]]->tafacesP[i]->four){	//if it's a quad draw a quad
										glBegin(GL_QUADS);
											glNormal3f(BallnormalsP[r][i][0],BallnormalsP[r][i][1], BallnormalsP[r][i][2]);
											glVertex3f(Balls1[0][r][i][0], Balls1[0][r][i][1], Balls1[0][r][i][2]);
											glVertex3f(Balls1[1][r][i][0], Balls1[1][r][i][1], Balls1[1][r][i][2]);
											glVertex3f(Balls1[2][r][i][0], Balls1[2][r][i][1], Balls1[2][r][i][2]);
											glVertex3f(Balls1[3][r][i][0], Balls1[3][r][i][1], Balls1[3][r][i][2]);
										glEnd();
									}else{
										glBegin(GL_TRIANGLES);
											glNormal3f(BallnormalsP[r][i][0],BallnormalsP[r][i][1], BallnormalsP[r][i][2]);
											glVertex3f(Balls1[0][r][i][0], Balls1[0][r][i][1], Balls1[0][r][i][2]);
											glVertex3f(Balls1[1][r][i][0], Balls1[1][r][i][1], Balls1[1][r][i][2]);
											glVertex3f(Balls1[2][r][i][0], Balls1[2][r][i][1], Balls1[2][r][i][2]);
										glEnd();
									}
	
							}
						
							glPopMatrix();
						//}
					}

				}
				/*
					if(fabricTime){

						
						glPushMatrix();

						for(int i = 0; i < fabricSize-fabricTop; i++){
							bool allowed = true;
							for(int v = 0; v < ripCount; v++){
								if(i+1 == rip[v] || i +fabricTop == rip[v] || i+fabricTop+1 == rip[v] || i == rip[v]){
									allowed = false;
								}
							}
							if(allowed){
								glPushMatrix();
	
								glCallList(ballColours[i]);
								
								
								//rotate triangles not the whole object, has to be done via transation
								
								if(i % fabricTop != 0){
									float x = Balls1[0][0][i][0] - fabricX;
									float y = Balls1[0][0][i][1] - fabricY;
									float z = Balls1[0][0][i][2] - fabricZ;
									float zRadians =  fabricAngle[i] * (3.14159/180);
									float z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glBegin(GL_QUADS);
									
									glVertex3f(x, y, z);
									x = Balls1[0][0][i+1][0] - fabricX;
									y = Balls1[0][0][i+1][1] - fabricY;
									z = Balls1[0][0][i+1][2] - fabricZ;
									zRadians =  fabricAngle[i+1] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									x = Balls1[0][0][i+fabricTop][0]- fabricX;
									y = Balls1[0][0][i+fabricTop][1] - fabricY;
									z = Balls1[0][0][i+fabricTop][2] - fabricZ;
									zRadians =  fabricAngle[i+fabricTop] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									x = Balls1[0][0][i+fabricTop+1][0] - fabricX;
									y = Balls1[0][0][i+fabricTop+1][1] - fabricY;
									z = Balls1[0][0][i+fabricTop+1][2] - fabricZ;
									zRadians =  fabricAngle[i+fabricTop+1] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									glEnd();
								}
								
								//}
								glPopMatrix();
							}
						}

						for(int i = fabricSize-1; i > fabricTop+1; i--){ // the split of the ripping
							bool allowed = true;
							for(int v = 0; v < ripCount; v++){
								if(i-1 == rip[v] || i -fabricTop == rip[v] || i-fabricTop-1 == rip[v] || i == rip[v]){
									allowed = false;
								}
							}
							if(allowed){
								glPushMatrix();

								glCallList(ballColours[i]);
								if(i % fabricTop-1 != 0){
									float x = Balls1[0][0][i][0] - fabricX;
									float y = Balls1[0][0][i][1] - fabricY;
									float z = Balls1[0][0][i][2] - fabricZ;
									float zRadians =  fabricAngle[i] * (3.14159/180);
									float z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glBegin(GL_QUADS);
									glVertex3f(x, y, z);
									x = Balls1[0][0][i-1][0] - fabricX;
									y = Balls1[0][0][i-1][1] - fabricY;
									z = Balls1[0][0][i-1][2] - fabricZ;
									zRadians =  fabricAngle[i-1] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									x = Balls1[0][0][i-fabricTop][0] - fabricX;
									y = Balls1[0][0][i-fabricTop][1] - fabricY;
									z = Balls1[0][0][i-fabricTop][2] - fabricZ;
									zRadians =  fabricAngle[i-fabricTop] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									x = Balls1[0][0][i-fabricTop-1][0] - fabricX;
									y = Balls1[0][0][i-fabricTop-1][1] - fabricY;
									z = Balls1[0][0][i-fabricTop-1][2] - fabricZ;
									zRadians =  fabricAngle[i-fabricTop-1] * (3.14159/180);
									z2 = cos(zRadians)*z -sin(zRadians)*x;
									x = sin(zRadians)*z +cos(zRadians)*x;
									z = z2;
									z += fabricZ;
									x += fabricX;
									y += fabricY;
									glVertex3f(x, y, z);
									glEnd();
								}
							
							glPopMatrix();
							}
						}
						
					}
				
				
				//DEBUG
				

					//glDisable(GL_TEXTURE_2D);
				//if(!cubeTime){
					/*
					if(!customObject){
						for(int i = 0; i < obsticleCounter; i++){
							glPushMatrix();
							
							glTranslatef( obsticleX[i],  +  obsticleY[i],  obsticleZ[i]);
							gluQuadricDrawStyle(sphere, GLU_FILL);
							//glEnable(GL_TEXTURE_2D);
							//glBindTexture(GL_TEXTURE_2D, ballTexture);
							gluQuadricTexture(sphere, GL_TRUE);
							gluQuadricnormals(sphere, GLU_SMOOTH);
							gluSphere(sphere, obsticleSize[i], 64, 32);
							glPopMatrix();
						}	
						if(cogs){
							for(int i = obsticleCounter; i < obsticleCounter + cogFSize; i++){
								glPushMatrix();
								
								glTranslatef( obsticleRX[i],  +  obsticleRY[i],  obsticleRZ[i]);
								gluQuadricDrawStyle(sphere, GLU_FILL);
								//glEnable(GL_TEXTURE_2D);
								//glBindTexture(GL_TEXTURE_2D, ballTexture);
								gluQuadricTexture(sphere, GL_TRUE);
								gluQuadricnormals(sphere, GLU_SMOOTH);
								gluSphere(sphere, obsticleSize[i], 64, 32);
								glPopMatrix();
							}
						}
						
					}*/
					/*
					if(dominoTime){
						//cout << "printing" << endl;
						GLUquadric* sphere = gluNewQuadric();
						for(int i = 0; i < dominoSize; i++){
							//cout << dominoVSize << endl;
							for(int c = 0; c < dominoVSize; c++){
								glPushMatrix();
								//glTranslatef(dominoX[i], dominoY[i], dominoZ[i]);
								glTranslatef(dominoVVX[i][c], dominoVVY[i][c], dominoVVZ[i][c]);
								
								gluQuadricDrawStyle(sphere, GLU_FILL);
								//glEnable(GL_TEXTURE_2D);
								//glBindTexture(GL_TEXTURE_2D, ballTexture);
								gluQuadricTexture(sphere, GL_TRUE);
								gluQuadricnormals(sphere, GLU_SMOOTH);
								gluSphere(sphere, dominoScale[i][c], 64, 32);
								glPopMatrix();
							}
						}	
						
					
					}*/
						

				
				
}

bool physicsMain::isFabric(){
	return fabricTime;
}
void physicsMain::moveFabricY(){ //move fabric in the y diretion
	for(int i =0; i < fabricTop; i++){
		Balls1[0][0][i][1] += 1; // move the top fabric parts up
		
	}
	for(int i = fabricTop; i < fabricSize; i++){ //move everything into the next, meaning everything is pulled and moves to the point higher
		for(int c = 0; c < fabricSize; c++){
						if(c != i){
							if((c+fabricTop) == i){
									Balls1[0][0][i][1] += (Balls1[0][0][c][1] - Balls1[0][0][i][1])/2;
									Balls1[0][0][i][2] += (Balls1[0][0][c][2] - Balls1[0][0][i][2])/2;
									Balls1[0][0][i][0] += (Balls1[0][0][c][0] - Balls1[0][0][i][0])/2;
									
									fabricAngle[i] += (fabricAngle[c] - fabricAngle[i])/2; // fabric angle is also moved
									c = fabricSize;
							}
						}
		}
	}
}
void physicsMain::rotateFabric(){ //rotation of the fabric
	for(int i =0; i < fabricTop; i++){
		fabricAngle[i] += 2; //move the top fabric angle 
	}
	for(int i = fabricTop; i < fabricSize; i++){
		for(int c = 0; c < fabricSize; c++){
						if(c != i){

								if((c+fabricTop) == i){
									

									fabricAngle[i] += (fabricAngle[c] - fabricAngle[i])/2; // gradient the angle by moving the angle to the higher points angle, giving a curve
									c = fabricSize;
									
								}

						}
		}
	}
}
void physicsMain::moveFabricX(int value){ //move fabric on the x axis
	for(int i =0; i < fabricTop; i++){
		Balls1[0][0][i][0] += value; //move the top fabric along the x axis (the x axis using rotation will always be where the fabric is flat no matter the rotation)
		
	}
	for(int i = fabricTop; i < fabricSize; i++){
		for(int c = 0; c < fabricSize; c++){
						if(c != i){

								if((c+fabricTop) == i){
								
									Balls1[0][0][i][1] += (Balls1[0][0][c][1] - Balls1[0][0][i][1])/2; // move everything into the next, meaning a pull illusion
									Balls1[0][0][i][2] += (Balls1[0][0][c][2] - Balls1[0][0][i][2])/2;
									Balls1[0][0][i][0] += (Balls1[0][0][c][0] - Balls1[0][0][i][0])/2;

									fabricAngle[i] += (fabricAngle[c] - fabricAngle[i])/2;
									c = fabricSize;
									
								}

						}
		}
	}
}

void physicsMain::moveTestX(int value){
	for(int i = 0; i < fabricSize; i++){
		Balls1[0][0][i][0] += value;
	
	}
}
void physicsMain::setRigidSplit(int split){
	rigidTop = split;
}
int physicsMain::getSize(){
	return jellySize;
}
void physicsMain::setFabricTest(){ // fabric but includes ripping
	fabricTime = true;
	horizontal = false;
	jellyTime = true;
	fabricTest = true;
	robotFalling = false;
	fabricFinished = false;
	for(int i = 0; i < 10; i++){
		rip[i] = -1;
	}
	ripCount = 0;
	setSplit(10);
	setRigidSplit(3);
	setAmount(20);
	if(processGradient != 4){
		setCoords(3, 15, 5);
	
		testMap();
	}
	
}
bool physicsMain::isFabricTest(){
	return fabricTest;
}
bool physicsMain::isMarble(){
	return marbleTime;
}
void physicsMain::runPhysics(){

	float randomWind = 0;
		//cout << "running" << endl;
		if(marbleTime){
			if(marbleMoved){
			for(int i = 0; i < marbleSize; i++){
				

				
					//if colliding get the angle of the obsticle and follow it
					
					float* angle = getCollidingAngle(marble[i][0], marble[i][1], marble[i][2], marbleDimensions);
					if(angle[0] != -1){
						float zDifference = (obsticleZ[collidingIP+2] - obsticleZ[collidingIP]);
						float yDifference = (obsticleY[collidingIP+2] - obsticleY[collidingIP]);
						float theLength = length(obsticleZ[collidingIP], obsticleY[collidingIP], obsticleZ[collidingIP-1], obsticleY[collidingIP-1]);
						
						marbleAngle[i][1] = ((atan(theLength) * (180 /3.14159)) +180);

						marble[i][1] += marbleDimensions;

					}else{

					}
					delete angle;
					marble[i][2] += ((marbleMo[i]) * sin(marbleAngle[i][1] * (3.14159 / 180)));
					marble[i][1] += ((marbleMo[i]) * cos(marbleAngle[i][1] * (3.14159 / 180)));
					marble[i][1] += ((marbleFall[i]) * sin(-90 * (3.14159 / 180)));

			}
			}
		}
		if(kettleTime && kettleBoil){ //particle effects, randomly move outwards, and check for collision with cogs. FOR stress test
			for(int i = 0; i < 200; i++){
				if(Balls1[1][0][i][1] < 26){
					Balls1[1][0][i][1] += 0.1 + get_random();
					
					Balls1[1][0][i][0] += get_random()- 0.5;
					Balls1[1][0][i][2] += get_random()- 0.5;
					kettleScale[i] += 0.005;

				}else{
					kettleScale[i] = 0.2;
					Balls1[1][0][i][1] = 0;
					Balls1[1][0][i][0] = 0;
					Balls1[1][0][i][2] = 0;
				}
				
				if(cogs && i % 4 == 0 && Balls1[1][0][i][1] > 10){ //if colliding with cogs
				float smokX = Balls1[1][0][i][0];
				float smokY = Balls1[1][0][i][1];
				float smokZ = Balls1[1][0][i][2];
				
				smokX += kettleSX;
				smokY += kettleSY;
				smokZ += kettleSZ;
				

							for(int c =0; c < cogSize; c++){
								for(int o = cogLength[c]; o < cogLength[c+1]; o++){
									
									float* angleR = getCustomCollidingAngle(smokX, smokY, smokZ, obsticleRX[o], obsticleRY[o], obsticleRZ[o], kettleScale[i]); //collidinh with pre rotated obsticle point
									if(angleR[0] != -1){
										

										cogSpin[c] = 5;
										cogAngle[c] += (obsticleRX[o] - smokX);

									}
									delete angleR;
								}
							}
						}
			}
			
			
			
			
			
		}
		
		if(fabricTime){ //fabric physics
		
		int setCounter = 0;
		for(int i = fabricTop; i < fabricSize - fabricTop; i++){
			setCounter = 0;
			if(!fabricFinished){
			bool colliding = false;
			float x = Balls1[0][0][i][0] - fabricX; // normalize the points for better rotation
			float y = Balls1[0][0][i][1] - fabricY;
			float z = Balls1[0][0][i][2] - fabricZ;
			float* results = rotateZ(x, y, z,fabricAngle[i]); //rotate the points
			
			x = results[0]; 
			y = results[1];
			z = results[2];
			
			delete results;
			
			x += fabricX; //translate the points
			y += fabricY;
			z += fabricZ;
			bool vacinity = false;
			
			float* angle = getCollidingAngle(x, y, z, 1); //check colliding on "perfect collisions"
			if(angle[0] != -1){
				ballMo[i]= 0;
				fallMo[i] = 0.1;

				colliding = true;
				Balls1[0][0][i][1] += 1;
				vacinity = true;
			}
			delete angle;

		int leeway = 3;	
		if(fabricTest){
			leeway = 4;
		}

				if(!vacinity){
					for(int c = 0; c < fabricSize; c++){
						if(c != i){
							if((c+fabricTop) == i +1 || (c+fabricTop) == i || (c+fabricTop) == i -1 || (c-fabricTop) == i +1 || (c-fabricTop) == i || (c-fabricTop) == i -1){ //if the looped fabric point is connected to the point in question
								if(c % fabricTop-1 !=0 && c % fabricTop !=0 && c % fabricTop+1 != 0){ //if the point is not on the border, so, 1 and 2 may be next to each other, and "connected", but on both ends, whenthe split happens
										if((c >= rip[0] && i <= rip[0]) || (c <= rip[0] && i >= rip[0])){

										}else{											
											float yDifference = Balls1[0][0][i][1] - Balls1[0][0][c][1];  //get the difference

											if(yDifference > ((1.1 * leeway))){//if the difference is big
												ballMo[i] =0;
												fallMo[i] =0;
												Balls1[0][0][i][1] -= 0.2; 
												//re attatch
												if(rip[0] == -1 && fabricTest){
													rip[0] = i;
													ripCount++;
													for(int c = 0; c < fabricSize; c++){
														fallMo[c] = 0;
														if(c != i){
															for(int v = 0; v < fabricTop; v++){
																if((c+fabricTop) == i +v || (c+fabricTop) == i || (c+fabricTop) == i -v || (c-fabricTop) == i +v || (c-fabricTop) == i || (c-fabricTop) == i -v){ //if the looped fabric point is connected to the point in question
																	if(c % fabricTop-1 !=0 && c % fabricTop !=0 && c % fabricTop+1 != 0){ //if the point is not on the border, so, 1 and 2 may be next to each other, and "connected", but on both ends, whenthe split happens
																		if((c >= rip[0] && i <= rip[0]) || (c <= rip[0] && i >= rip[0])){
																				rip[ripCount] = c;
																				ripCount++;
																				for(int i = 0; i < divisionEnd; i++){
																					jellyMo[p][i][0][0] = velocity;
																					
																				}																				
																		}
																			
																	}
																	
																}
															}
															
														}
														
													}
													resetPhysics();
													fabricTest = false;
			
											}
											}
											if(yDifference < -((1.1* leeway ))){// opposite direction
												ballMo[i] =0;
												fallMo[i] =0;
												Balls1[0][0][i][1] += 0.2;
												
												if(rip[0] == -1 && fabricTest){
													rip[0] = i;
													ripCount++;
													for(int c = 0; c < fabricSize; c++){
														fallMo[c] = 0;
														if(c != i){
															for(int v = 0; v < fabricTop; v++){
																if((c+fabricTop) == i +v || (c+fabricTop) == i || (c+fabricTop) == i -v || (c-fabricTop) == i +v || (c-fabricTop) == i || (c-fabricTop) == i -v){ //if the looped fabric point is connected to the point in question
																	if(c % fabricTop-1 !=0 && c % fabricTop !=0 && c % fabricTop+1 != 0){ //if the point is not on the border, so, 1 and 2 may be next to each other, and "connected", but on both ends, whenthe split happens
																		if((c >= rip[0] && i <= rip[0]) || (c <= rip[0] && i >= rip[0])){
																				rip[ripCount] = c;
																				ripCount++;	
																				for(int i = 0; i < divisionEnd; i++){
																					jellyMo[p][i][0][0] = velocity;
																					
																				}
																		}
																			
																	}
																	
																}
															}
															
														}
														
													}
													resetPhysics();
													fabricTest = false;
												}	//cout << "here" << endl;

											}
										}

								}
							}
						}
					}
				}

					if(!fabricTest){	

						Balls1[0][0][i][1] = Balls1[0][0][i][1] + (3 * fallMo[i]) * sin(-90 * (3.14159 / 180)); //push the whole fabric down
						if(rip[0] != -1){
	
							for(int c = 0; c < fabricSize; c++){
									if (c < rip[0]){
										if(Balls1[0][0][c][0] > Balls1[0][0][0][0]){
											Balls1[0][0][c][0] -= 0.6 / c;
											
										}else{
											setCounter++;
										}
										
									}else{
										if(Balls1[0][0][c][0] < Balls1[0][0][fabricSize-1][0]){
											Balls1[0][0][c][0] += 0.6 / (fabricSize - c);
										}
									}
							}
						}
					}

					if(ballMo[i] > 0.005){
						ballMo[i]-= 0.005; //decrease momentum
					}
					if (fallMo[i]< 2) {
						fallMo[i] += 0.05; //increase gravity
					}


				 }
			}
			if(setCounter >= rip[0]-5 && rip[0] != -1){
				fabricFinished = true;

			}

		}
		if(ropeTime){ //rope physics
			if(!holdingRope){ 
				
				float speed = addedSpeed;
				for(int i = 0; i < ropeSize; i++){
					bool change = false;
				for(int v = i * ropeCounter; v < (i+1) * ropeCounter; v++){ //loop through the 1D array
					float decrease = (v - (i * ropeCounter)) + 3 ;
					
					
					
					
					if(ropeLastX[i] > 0.01){ //if there should be movement
						ropePrio[i] += 0.03;

					
						if(ropeDirection[i]){ //if left movement
							if(ropeX[i * ropeCounter] < ropeLastX[i]){
								ropeAngle[v] += ((ropeCounter - decrease) * 2) * 3.14159/180; // swinging angle
								ropeY[v] += sin(ropeAngle[v] * 3.14159/180); //sin is a curve
								ropeX[v] -= 1 / (sin(ropeAngle[v] * 3.14159/180) - (decrease));  //move in the x direction increasing and decreasing througout the swing

							}else{
								change = true; //otherwise flip

							}	
						}else{ //otherwise right movement
							if(ropeX[i * ropeCounter] > ropeX[i* ropeCounter + (ropeCounter -1)] - (ropeLastX[i] - ropeX[i* ropeCounter + (ropeCounter -1)] )){
								ropeAngle[v] -= ((ropeCounter - decrease) * 2) * 3.14159/180; //swinging angle
								ropeY[v] -= sin(ropeAngle[v] * 3.14159/180); //sin is a curve
								ropeX[v] += 1 / (sin(ropeAngle[v] * 3.14159/180) - (decrease)); //move in the x direction increasing and decreasing throughout the swing

							}else{
								change = true; //otherwise flip

							}							
						}
					}
					int colliding = 0;
					for(int c = 0; c < ropeSize; c++){ //rope ball collisions
						
						if(c != i){
							int counter = i * ropeCounter;
							int counter2 = c * ropeCounter;
							float* angle  = getCustomCollidingAngle(ropeX[counter], ropeY[counter], ropeZ[counter] ,ropeX[counter2], ropeY[counter2], ropeZ[counter2], 1);
							if(angle[0] != -1 && ropePrio[i] > ropePrio[c]){ //priority is important to know which ball is stronger (been moving the most)
								colliding++;
								ropePrio[c] += 0.03;
								ropeDirection[c] = ropeDirection[i]; //give it the same direction
								
								ropeX[counter2] -= ropeX[counter] - ropeX[counter2]; //kick the object out the other if there is an overlap
								ropeX[counter] += ropeX[counter] - ropeX[counter2];

								ropeLastX[c] = ropeLastX[i] - (ropeLastX[i]/9); //decrease the moving distance limit
								
								change = true; //flip 

							}
							delete angle;
						}
					}
					
				}
				if(change){ //flip
					addedSpeed = 5;
					ropeYDirection[i] = !ropeYDirection[i];
					ropeDirection[i] = !ropeDirection[i];
					if(ropeLastX[i] > 0){
						ropeLastX[i] -= (ropeLastX[i]/10); //decrease the moving distance limit
					}
				
				}
				}
				
			}
		}else if(meltingTime){
			float meltSlow[jellySize];
			for(int r = 1; r < jellySize; r++){
				meltSlow[r] = 1;

				int amountOnFloor = 0;
				if(jellyMo[p][r][0][0] > 0.005){
					jellyMo[p][r][0][0] -= 0.005; //decrease the momentum over time
				}else{
					jellyMo[p][r][0][0] = 0;
				}
				
				for(int i = 0; i < ballJSize[p][r]; i++){ //look at a skeleton of the model for performance
					
					for(int v = 0; v < 3; v++){

							
						int type = v;
						float intX = Balls1[type][r][i][0]; //ints are better for jelly and don't change much when harder
						float intY = Balls1[type][r][i][1];
						float intZ = Balls1[type][r][i][2];
						
						intY += rigidY[p][r]; //translate to parent origin
						intX += rigidX[p][r];
						intZ += rigidZ[p][r];
						
						
						
						intY -= 5;
						if(!collidedM[r][i]){
							float* angle = getCollidingAngle(intX, intY, intZ, ballHeight); //check against perfect collisions
				
							
							if(angle[0] != -1){
								
	
								collidedM[r][i] = true;
								meltSlow[r] -= 50 / ballJSize[p][r];

								
							}
							UpdateFace(i, r);
							delete angle;
						}else{
							meltSlow[r] -= 50 / ballJSize[p][r];
							
						}
					}
					
				}

				for(int i = 0; i < ballJSize[p][r]; i++){
					if(!collidedM[r][i]){

						for(int v = 0; v < 3; v++){
							Balls1[v][r][i][1] -= meltSlow[r];

						}
					}

				}
			}
			
		}else if (fluidTime){ //jelly physics

			int count = 1;
			if(robot){
				count = 0;
			}
		
			for(int r = count; r < fluidSize; r++){
				
				float beforeFall = fallMo[r];


				int amountOnFloor = 0;


					if(ballMo[r] > 0.05){
						ballMo[r] -= 0.001;
					}


						float intX =  Balls1[0][0][r][0]; //ints are better for jelly and don't change much when harder
						float intY =  Balls1[0][0][r][1];
						float intZ =  Balls1[0][0][r][2];

						
						
						bool doneMoved = false;
						
						float* angle = getCollidingAngle(intX, intY, intZ, 1); //check against perfect collisions
						
						if(angle[0] != -1){

							amountOnFloor += 1;

	
							fabricAngle[r] = (angle[0]-180);

							fabricAngleZ[r] =  angle[1] - 180;
							fallMo[r] = 0.0001;
	
						}
						delete angle;
						
						
						for (int o = 0; o < fluidSize; o++) { //check against other objects
								float x2 = Balls1[0][0][o][0];
								float y2 = Balls1[0][0][o][1];
								float z2 = Balls1[0][0][o][2]; //simple for performance
					

								if (o != r) { //make sure not colliding with itself
									
									float* angle2 = getCustomCollidingAngle(intX, intY, intZ, x2, y2, z2, ballHeight);
									if(angle2[0] != -1){
										amountOnFloor += 3;
										ballMo[r] -= 0.001;

											fabricAngleZ[r] = (angle2[1]  - 180);

											fabricAngle[r] = (angle2[0]  - 180);


										}
										
									//}
									delete angle2;
								}
						}
						if(handTime){ //hand can effect objects in realtime
							for(int o = 0; o < handCounter; o++){
								float hX = handX[0] + handRX[o];
								float hY = handY[0] + handRY[o];
								float hZ = handZ[0] + handRZ[o];
								float differenceX = intX - hX;
									float differenceZ = intZ - hZ;
									float differenceY = intY - hY;

									if(collision(intX, intY, 1, hX, hY, 1)){

										if(collision(intZ, intY,1, hZ, hY, 1)){
	
											float a = (atan2(obsticleRY[o] - intY, obsticleRX[o] - intX));
											float az = (atan2(obsticleRY[o] - intY, obsticleRZ[o] - intZ));
											float ay = (atan2(obsticleRY[o], intY) *180/3.14159);
		
													if(stickIt){
														Balls1[0][0][r][0] -= (obsticleRX[o] - intX)/(2);
														Balls1[0][0][r][2] -= (obsticleRZ[o] - intZ)/(2);
													}
		
													rigidFall[p][r] = 0.0001;

												
												rigidFall[p][r] = 0.0001;
											//if(a > 10 && a < -10){
												fabricAngle[r] = (a- 180);
												fabricAngleZ[r] = (az- 180);

											
											Balls1[0][0][r][2] += (((2/sticky)*ballMo[r])) * cos(fabricAngleZ[r] * (3.14159 / 180));
											Balls1[0][0][r][0] += (((2/sticky)*ballMo[r])) * cos(fabricAngle[r] * (3.14159 / 180));
											
											amountOnFloor+=1;
											o = handCounter;
											//i = ballJSize[r];
											

										}
									}
								//}
								//delete angle2;
							}
							
						}

				if(ballMo[r] > 0.05) {
					if(fallMo[r] != 0){
					Balls1[0][0][r][1] = Balls1[0][0][r][1] + (2 * fallMo[r]) * sin(-90 * (3.14159 / 180)); // gravity
						if(fallMo[r] < 2){ //2 is terminal velocity
							fallMo[r] += 0.1; //increase until terminal velocity.
						}
					}

					if(fabricAngle[r] != 0){ //move the object on it's angles, as fast as it's momentum, every loop. 
						Balls1[0][0][r][0] += ((slip*ballMo[r])/sticky) * cos(fabricAngle[r] * (3.14159 / 180));

					}
					if(fabricAngleZ[r] != 0){
						Balls1[0][0][r][2]+= ((slip*ballMo[r])/sticky) * cos(fabricAngleZ[r] * (3.14159 / 180));
					}

				
							
					
				}
					
			}
									
		//}
		}else if (jellyTime && robotFalling && !cubeTime){ //jelly physics
			int statCounter = 0;
			if(statTime){
				
				for(int r = 1; r < jellySize; r++){
					if(getStats[r] == true){
						statCounter++;
					}
				}
				if(statCounter == jellySize -1){
					for(int r = jellySize -1; r > jellySize -2; r--){
						for(int i = 0; i < ballJSize[p][r]; i+= rigidIncrement[p][r]){ 
							cout << "face: " << std::to_string(i) << ", heat: " << heatColour[r][i][0] << endl;
						}
						
					}
				}
			}
			int count = 1;
			if(robot){
				count = 0;
			}
		
			for(int r = count; r < jellySize; r++){
				
				hitGround[p] = false;

				int amountOnFloor = 0;
				
				float oldXAngle = newRigidXAngle[p][r];
				float oldZAngle = newRigidZAngle[p][r];
				
				float beforeFall = rigidFall[p][r];
				int coll = 0;
				for(int i = 0; i < ballJSize[p][r]; i+=rigidIncrement[p][r]){ //look at a skeleton of the model for performance
					
					for(int v = 0; v < 3; v++){
						
							
						int type = v;
						float intX =  (int) Balls1[type][r][i][0]; //ints are better for jelly and don't change much when harder
						float intY =  (int) Balls1[type][r][i][1];
						float intZ =  (int) Balls1[type][r][i][2];
					
						intX *= ballHeight;
						intY *= ballHeight;
						intZ *= ballHeight;
						
						float* results = rotateXZ(intX, intY, intZ, rigidXAngle[p][r], rigidZAngle[p][r]);  //rotate along the x and z axis
						intX =  results[0];
						intY =  results[1];
						intZ =  results[2];
						delete results;
						intY += rigidY[p][r]; //translate to parent origin
						intX += rigidX[p][r];
						intZ += rigidZ[p][r];
						
						
						bool doneMoved = false;
						if(fabricTest){
							int increment = 2;
							for(int f = 0; f < fabricSize; f+= increment){
								increment = rand() % 4 + 1;
								float x2 = Balls1[0][0][f][0];
								float y2 = Balls1[0][0][f][1];
								float z2 = Balls1[0][0][f][2];
								float* angle2 = getCustomCollidingAngle(intX, intY, intZ, x2, y2, z2, ballHeight);
								if(angle2[0] != -1){
									if(jellyMo[p][r][0][0] > 0.1){
										Balls1[0][0][f][1] -= (ballHeight/4);
									}
											if(heatMap && jellyMo[p][r][0][0] > 0.1){
												for(int c = i; c < i + rigidIncrement[p][r]; c++){
													if(heatColour[r][c][0] < 1){
														heatColour[r][c][0] += 0.05;
														heatColour[r][c][1] -= 0.05;
													
													}
												}
											}
										zrDirection[p][r] = !zrDirection[p][r];
											newRigidZAngle[p][r] = (angle2[1]  - 180);
											
											newRigidXAngle[p][r] = (angle2[0]  - 180);
											
											rigidFall[p][r] = 0.0001; //get rid of gravity
											
											jellyPrio[p][r] += 0.2;

											//if(!mapCollisionCounter[r] && divider[r] > 1){ //if jelly time, tamper the points for effect
	
											//	TamperJelly( jellyTamper, angle2[0], angle2[2], angle2[1], divider[r], i, r);
	
																	
											//}else{
												if(!xrDirection[p][r]){
													newRigidXAngle[p][r] = (180 - angle2[0]); //opposite of colliding angle
												}
												if(!zrDirection[p][r]){
													newRigidZAngle[p][r] = (stick - angle2[1]); //opposite of colliding z angle
												}
											//}

								}	
								delete angle2;
							}
							
						}
						
						
											
											
											
						if(handTime){ // hand collides with objects and increases the velocity, causing a chain reaction and movement, the rest of the function carries out. 
							for(int o = 0; o < handCounter; o++){
								float hX = handX[0]+ handRX[o];
								float hY = handY[0] +handRY[o];
								float hZ = handZ[0] + handRZ[o];
								float differenceX = intX - hX;
									float differenceZ = intZ - hZ;
									float differenceY = intY - hY;
									if(differenceX * differenceX < 5 && differenceZ * differenceZ < 5 && differenceY* differenceY < 5 ){
										float* angle2 = getCustomCollidingAngle(intX, intY, intZ, hX, hY, hZ, ballHeight);
										
										if(angle2[0] != -1){
											
											stopTimer[p][r] = 0;
				xrDirection[p][r] = false;
				zrDirection[p][r] = false;
				rigidXAngle[p][r] = 0;
				rigidZAngle[p][r] = 0;
				rigidYAngle[p][r] = -90;
				gravityX[p][r] = 0;
				gravityZ[p][r] = 0;
				newRigidZAngle[p][r] = 0;
				newRigidXAngle[p][r] = 0;
				collidingO[r] = -1;
				rigidFall[p][r] = 0.5;
				jellyMo[p][r][0][0] = velocity;
				gravityMo[p][r] = 1;
				
									//if(collision(intX, intY, ballHeight, hX, hY, ballHeight)){

										//if(collision(intZ, intY, ballHeight, hZ, hY, ballHeight)){
											hitGround[r] = true;
												float a = (atan2(obsticleRY[o] - intY, obsticleRX[o] - intX));
											float az = (atan2(obsticleRY[o] - intY, obsticleRZ[o] - intZ));
											float ay = (atan2(obsticleRY[o], intY) *180/3.14159);
										//	handCollided = true;
											jellyPrio[p][r] += 0.3;
											//hitGround[r] = false;
											jellyMo[p][r][0][0] += 0.01;
											
												if(processGradient != 1){
													jellyMo[p][r][0][0] = velocity;
													jellyMo[p][r][i][type] = velocity;
												}else{
													jellyMo[p][r][0][0] = 0.3;
													jellyMo[p][r][i][type] = 0.3;
												}

											//	xrDirection[p][r] = !xrDirection[p][r];

												newRigidXAngle[p][r] = (a- 180);
											//	if(!xrDirection[p][r]){
											//		newRigidXAngle[p][r] = (180 - a);
												//}
											//	zrDirection[p][r] = !zrDirection[p][r];

												newRigidZAngle[p][r] = (az - 180);
												//	/	if(!zrDirection[p][r]){
												//			newRigidZAngle[p][r] = (180 - az);
												//		}
	
											//	doneMoved = true;

										//	if(!mapCollisionCounter[r] && divider[r] > 1){ // if gradient is soft, tamper jelly
												
										//			TamperJelly(0.01*2, a - 180, ay - 180, az- 180, divider[r], i, r);

										//	}
	
											stopTimer[p][r] = 0;
											rigidZ[p][r] = rigidZ[p][r] + (0.5) * cos(newRigidZAngle[p][r] * (3.14159 / 180));
											rigidX[p][r] = rigidX[p][r] + (0.5) * cos(newRigidXAngle[p][r] * (3.14159 / 180));
											//rigidFall[p][r] += 0.001;
										//	stopTimer[p][r] = 0;
/*

											if(heatMap && jellyMo[p][r][0][0] > 0.1){
												for(int c = i; c < i + rigidIncrement[p][r]; c++){
													if(heatColour[r][c][0] < 1){
														heatColour[r][c][0] += 0.05;
														heatColour[r][c][1] -= 0.05;
													
													}
												}
											}

											float a = (atan2(obsticleRY[o] - intY, obsticleRX[o] - intX));
											float az = (atan2(obsticleRY[o] - intY, obsticleRZ[o] - intZ));
											float ay = (atan2(obsticleRY[o], intY) *180/3.14159);
	
											//		if(stickIt){
											//			rigidX[p][r] -= (obsticleRX[o] - intX)/(1 + divider[r]);
											//			rigidZ[p][r] -= (obsticleRZ[o] - intZ)/(1 + divider[r]);
											//		}

													//rigidFall[p][r] = 0.0001;
													//jellyMo[p][r][0][0] += rigidFall[p][r];
													rigidFall[p][r] = 0.0001;
													gravityX[p][r] = 0;
													gravityZ[p][r] = 0;
													gravityZ[p][r] = 0;
	
										//	mapCollisionCounter[r] = false;
											if(processGradient != 1){
												jellyMo[p][r][0][0] = velocity;
												jellyMo[p][r][i][type] = velocity;
											}else{
												jellyMo[p][r][0][0] = 0.3;
												jellyMo[p][r][i][type] = 0.3;
											}

											//	xrDirection[p][r] = !xrDirection[p][r];

												newRigidXAngle[p][r] = (a- 180);
												if(!xrDirection[p][r]){
													newRigidXAngle[p][r] = (180 - a);
												}
											//	zrDirection[p][r] = !zrDirection[p][r];

												newRigidZAngle[p][r] = (az - 180);
														if(!zrDirection[p][r]){
															newRigidZAngle[p][r] = (180 - az);
														}
	
											//	doneMoved = true;

											if(!mapCollisionCounter[r] && divider[r] > 1){ // if gradient is soft, tamper jelly
												
										//			TamperJelly(0.01*2, a - 180, ay - 180, az- 180, divider[r], i, r);

											}
	
											stopTimer[p][r] = 0;
											rigidZ[p][r] = rigidZ[p][r] + ((2/sticky)*(0.5)/divider[r]) * cos(newRigidZAngle[p][r] * (3.14159 / 180));
											rigidX[p][r] = rigidX[p][r] + ((2/sticky)*(0.5)/divider[r]) * cos(newRigidXAngle[p][r] * (3.14159 / 180));
											
											amountOnFloor+=1;
											o = handCounter;
*/
											o = handCounter;
											

									//	}
									}
								}

							}
							
						}
						
						for (int o = 0; o < jellySize; o++) { //check against other objects
								float x2 = rigidX[p][o];
								float y2 = rigidY[p][o];
								float z2 = rigidZ[p][o]; //simple for performance
					

								if (o != r) { //make sure not colliding with itself
									collidingO[r] = -1;
									float* angle2 = getCustomCollidingAngle(intX, intY, intZ, x2, y2, z2, ballHeight);
									if(angle2[0] != -1){
										coll++;
										collidingO[r] = o;
										amountOnFloor += 3;
										if(jellyPrio[p][o] > jellyPrio[p][r]){
											rigidYAngle[p][r] = (angle2[2]);
											xrDirection[p][r] = !xrDirection[p][r];
											zrDirection[p][r] = !zrDirection[p][r];
											
										//xrDirection[p][o] = !xrDirection[p][o];
										//	zrDirection[p][o] = !zrDirection[p][o];
											
											
											if(heatMap && jellyMo[p][r][0][0] > 0.1){
												for(int c = i; c < i + rigidIncrement[p][r]; c++){
													if(heatColour[r][c][0] < 1){
														heatColour[r][c][0] += 0.05;
														heatColour[r][c][1] -= 0.05;
													
													}
												}
											}

											rigidY[p][r] += (rigidY[p][r] - rigidY[p][o])/5;
											
											rigidZ[p][r] += (rigidZ[p][r] - rigidZ[p][o])/5;
											rigidX[p][r] += (rigidX[p][r] - rigidX[p][o])/5;
											
											stopTimer[p][r] ++;
											gravityX[p][r] -= gravityX[p][r]/3;
											gravityZ[p][r] -= gravityZ[p][r]/3;
											
												jellyMo[p][r][0][0] = 0.0001;
											
											//	if (jellyMo[p][o][0][0] > 0.005){
											//		jellyMo[p][r][0][0] = jellyMo[p][o][0][0] - 0.005;
											//	}//
											//	if (jellyMo[p][o][0][0] > 0.01){
												jellyMo[p][o][0][0] -= (jellyMo[p][o][0][0])/2;
											//	}
												
												gravityZ[p][r] = 0;
												gravityX[p][r] = 0;
													
													//jellyMo[p][o][0][0] += 0.05;
			
											rigidFall[p][r] = 0.00001;//(rigidFall[p][r]/2); //get rid of gravity
											jellyPrio[p][r] += 0.01;
											jellyPrio[p][o] += 0.2;
											if(divider[r] > 1){ //if jelly time, tamper the points for effect
	
												//TamperJelly(jellyTamper, angle2[0] - 180, angle2[2] - 180, angle2[1] - 180, divider[r], i, r);
												//TamperJelly(jellyTamper, newRigidXAngle[p][o], rigidYAngle[p][o], newRigidZAngle[p][o], divider[r], i, r);
																	
											}
											
												
											if(newRigidXAngle[p][o] - newRigidXAngle[p][r] > 100 || newRigidXAngle[p][r] - newRigidXAngle[p][o] < -100){
												rigidX[p][r] = rigidX[p][r] + (0.5) * cos((angle2[0] - 180 ) * (3.14159 / 180));
											
												if(xrDirection[p][o]){
													newRigidXAngle[p][o] = (180 - angle2[0]); //opposite of colliding angle
												}else{
													newRigidXAngle[p][o] = (angle2[0] - 180);
												}
												
											}else{
												rigidZAngle[p][r] += 1;
											}
											if(newRigidZAngle[p][o] - newRigidZAngle[p][r] > 100 || newRigidZAngle[p][r] - newRigidZAngle[p][o] < -100){
												rigidZ[p][r] = rigidZ[p][r] + (0.5) * cos((angle2[1] - 180 ) * (3.14159 / 180));
												if(zrDirection[p][o]){
													newRigidZAngle[p][o] = (180 - angle2[1]); //opposite of colliding z angle
												}else{
													newRigidZAngle[p][o] = (angle2[1] - 180);
												}
											}else{
												rigidXAngle[p][r] += 1;
											}
											//rigidZ[p][r] = rigidZ[p][r] + (0.5) * cos((angle2[1] - 180 ) * (3.14159 / 180));
											//rigidX[p][r] = rigidX[p][r] + (0.5) * cos((angle2[0] - 180 ) * (3.14159 / 180));
											
											TamperJelly(0.01*2, angle2[0] - 180, angle2[2] - 180, angle2[1] - 180, divider[r], i, r);
											
											o = jellySize;
										}
										
									}else{
										collidingO[r] = -1;
									}
									delete angle2;
								}
						}
						
		
				
						float* angle = getCollidingAngle(intX, intY, intZ, ballHeight); //check against perfect collisions
						
						if(angle[0] != -1){
							amountOnFloor += 3;
							constJelly[r][(int) (i / rigidIncrement[p][r])] = 4;
							//xrDirection[p][r] = !xrDirection[p][r]; //doing this will shake the model out of problems
							//zrDirection[p][r] = !zrDirection[p][r];
							//if(!mapCollisionCounter[r]){
								//rigidY[p][r] += jellyMo[p][r][0][0] + rigidFall[p][r];
								rigidY[p][r] += jellyMo[p][r][0][0] + rigidFall[p][r];//(obsticleY[collidingI] - rigidY[p][r])/10;
								//rigidX[p][r] -= (obsticleX[collidingI] - rigidX[p][r])/10;
								//rigidZ[p][r] -= (obsticleZ[collidingI] - rigidZ[p][r])/10;
								
								rigidZ[p][r] = rigidZ[p][r] + (0.5) * cos((180 - angle[1]) * (3.14159 / 180));
								rigidX[p][r] = rigidX[p][r] + (0.5) * cos((180 - angle[0]) * (3.14159 / 180));
								
							//}

							
							hitGround[r] = true;
							
							
								rigidYAngle[p][r] = (angle[2]);
								if(heatMap && jellyMo[p][r][0][0] > 0.1){
												for(int c = i; c < i + rigidIncrement[p][r]; c++){
													if(heatColour[r][c][0] < 1){
														heatColour[r][c][0] += 0.05;
														heatColour[r][c][1] -= 0.05;
													
													}
												}
											}
											

						
							float xAngle = 180 - angle[0];
							if((xAngle) - newRigidXAngle[p][r] > 50 || (xAngle) - newRigidXAngle[p][r] < -50){
								newRigidXAngle[p][r] = (xAngle );
							}
							if (jellyMo[p][r][0][0] > 0.01){
								jellyMo[p][r][0][0] -= 0.01;
							}
							float zAngle = 180 - angle[1];
							if((zAngle)- newRigidZAngle[p][r] > 50 || (zAngle)- newRigidZAngle[p][r] < -50){
								newRigidZAngle[p][r] =  zAngle  ;
							}
							//newRigidXAngle[p][r] = (180 - angle[0]);
							if (jellyMo[p][r][0][0] > 0.01){
								jellyMo[p][r][0][0] -= 0.01;
							}
												
						//	newRigidZAngle[p][r] =  180 - angle[1]  ;

							rigidFall[p][r] = (rigidFall[p][r]/2);
							
							
							//rigidZ[p][r] = rigidZ[p][r] + (((2/sticky)*jellyMo[p][r][0][0])/sticky) * cos((angle[1] - 180) * (3.14159 / 180));
							//rigidX[p][r] = rigidX[p][r] + (((2/sticky)*jellyMo[p][r][0][0])/sticky) * cos((angle[0] - 180) * (3.14159 / 180));
											


							//jellyMo[p][r][0][0]  -= 0.01;
							
							jellyPrio[p][r] += 0.6; //more priority if hitting obsticle, so it doesn't get pushed into 
							//if(!mapCollisionCounter[r] && divider[r] > 1){ // if gradient is soft, tamper jelly
								
									TamperJelly(0.01*2, angle[0] - 180, angle[2] - 180, angle[1] - 180, divider[r], i, r);
								//}
							//}
							//if(!xrDirection[p][r]){
							//						newRigidXAngle[p][r] = (180 - angle[0]) + 20; //opposite of colliding angle
							//					}
							//					if(!zrDirection[p][r]){
							//						newRigidZAngle[p][r] = (180- angle[1]) + 20; //opposite of colliding z angle
							//					}
							//					
							
						}else{
							if( i != 0){
								if(divider[r] > 1){
								//	UpdateFaces(i, r);
									restoreFromJelly(divider[r], i, r);
								}

							}
						}
						delete angle;
						
					
						if(cogs){ //if colliding with cogs
							for(int c =0; c < cogSize; c++){
						for(int o = cogLength[c]; o < cogLength[c+1]; o++){
							
							float differenceX = intX - obsticleRX[o];
									float differenceZ = intZ - obsticleRZ[o];
									float differenceY = intY - obsticleRY[o];
									if(differenceX * differenceX < 5 && differenceZ * differenceZ < 5 && differenceY* differenceY < 5 ){ // in vacinity
	
									if(collision(intX, intY, ballHeight, obsticleRX[o], obsticleRY[o], obsticleSize[o])){

										if(collision(intZ, intY, ballHeight, obsticleRZ[o], obsticleRY[o], obsticleSize[o])){
											
											
											jellyPrio[p][r] += 0.3;

											if(cogReaction){
												cogAngle[c] += (obsticleRX[o] - intX);
											}
											float a = (atan2(obsticleRY[o] - intY, obsticleRX[o] - intX));
											float az = (atan2(obsticleRY[o] - intY, obsticleRZ[o] - intZ));
											float ay = (atan2(obsticleRY[o], intY) *180/3.14159);

													rigidY[p][r] -= (obsticleRY[o] - intY)/(1 + divider[r]);
													if(stickIt){
														rigidX[p][r] -= (obsticleRX[o] - intX)/(1 + divider[r]);
														rigidZ[p][r] -= (obsticleRZ[o] - intZ)/(1 + divider[r]);
													}

													//rigidFall[p][r] = 0.0001;
	
											mapCollisionCounter[r] = false;
											jellyMo[p][r][0][0] = 0.2;
											jellyMo[p][r][i][type] = 0.2;
											
		
												//xrDirection[p][r] = !xrDirection[p][r];

												newRigidXAngle[p][r] = (a- 180);
												if(!xrDirection[p][r]){
													newRigidXAngle[p][r] = (180 - a);
												}
												//zrDirection[p][r] = !zrDirection[p][r];

												newRigidZAngle[p][r] = (az - 180);
														if(!zrDirection[p][r]){
															newRigidZAngle[p][r] = (180 - az);
														}
		
												doneMoved = true;

											if(!mapCollisionCounter[r] && divider[r] > 1){ // if gradient is soft, tamper jelly
												
											//		TamperJelly(0.01*2, a - 180, ay - 180, az - 180, divider[r], i, r);

											}
			
											
											rigidZ[p][r] = rigidZ[p][r] + (((2/sticky)*jellyMo[p][r][0][0])/sticky) * cos(newRigidZAngle[p][r] * (3.14159 / 180));
											rigidX[p][r] = rigidX[p][r] + (((2/sticky)*jellyMo[p][r][0][0])/sticky) * cos(newRigidXAngle[p][r] * (3.14159 / 180));
											
											amountOnFloor+=1;
											
											//TamperJelly(1, newRigidXAngle[p][r], rigidYAngle[p][r], newRigidZAngle[p][r], divider[r], i, r); //tamper jelly
											o = obsticleCounter + cogFSize;
											//i = ballJSize[r];
											

										}
									}
								}
							}	
						}
						}
					}

					if(constJelly[r][(int) (i / rigidIncrement[p][r])] > 0){
						//cout << (int) (i / rigidIncrement[p][r]) << endl;
					constJelly[r][(int) (i / rigidIncrement[p][r])] -= 1;
				//	TamperJelly(jellyTamper, newRigidXAngle[p][r], rigidYAngle[p][r], newRigidZAngle[p][r], divider[r], i, r); //tamper jelly
				}
				
				
				
				
				
				} //end of loop for faces, now into parent roles
				float fallThreshold = 1.5;
				int stopMax = 50;
				int stopTimerThreshold = 10;
				if(((rigidZAngle[p][r] - newRigidZAngle[p][r] < stopTimerThreshold) || (rigidZAngle[p][r] - newRigidZAngle[p][r] > -stopTimerThreshold)) && rigidZAngle[p][r] != 0 && ((gravityX[p][r] < fallThreshold && gravityX[p][r] > -fallThreshold) && (gravityZ[p][r] < fallThreshold && gravityZ[p][r] > -fallThreshold))){
					//cout << newRigidZAngle[p][r] << ":" << rigidZAngle[p][r] << endl;
					stopTimer[p][r] ++;
					//cout << stopTimer[p][r] << endl;

				}else if(((rigidXAngle[p][r] - newRigidXAngle[p][r] < stopTimerThreshold) || (rigidXAngle[p][r] - newRigidXAngle[p][r] > -stopTimerThreshold)) && rigidXAngle[p][r] != 0 && ((gravityX[p][r] < fallThreshold && gravityX[p][r] > -fallThreshold) && (gravityZ[p][r] < fallThreshold && gravityZ[p][r] > -fallThreshold))){
					//cout << newRigidXAngle[p][r] << ":" << rigidXAngle[p][r] << endl;
					stopTimer[p][r] ++;
					//stopTimer[p][r] = 0;
				}else{
					stopTimer[p][r] = 0;
				}
				
				float gravIncrease = 0.06;
				float terminalFall =  1;
				if(stopTimer[p][r] < stopMax){
				
				//cout << "rx" << newRigidXAngle[p][r] << endl;
				//cout << "rz" << newRigidZAngle[p][r] << endl;
				
					if((hitGround[r] && collidingO[r] == -1) || (hitGround[r] || (collidingO[r] != -1 && jellyPrio[p][r] > jellyPrio[p][collidingO[r]]))){
					
					//cout << "Az" << newRigidZAngle[p][r] << " ax" << newRigidXAngle[p][r] << endl;
					//if(jellyMo[p][r][0][0] > 0.005){
							if((newRigidZAngle[p][r] > 220 && newRigidZAngle[p][r] < 320) ){
								if(gravityZ[p][r] < terminalFall  && gravityZ[p][r] > -terminalFall ){
								if(newRigidZAngle[p][r] > 270){
									gravityZ[p][r] -= gravIncrease;
								}else{
									gravityZ[p][r] += gravIncrease;
								}
								
								if(gravityMo[p][r] > 3){
									gravityMo[p][r] -= 2;
								}
								}
							}else {

								gravityMo[p][r] += 0.075 ;
	
								if(rigidZAngle[p][r] - newRigidZAngle[p][r] < 60 && rigidZAngle[p][r]- newRigidZAngle[p][r] > -60){
									//gravityZ[p][r] = 0;
									jellyPrio[p][r] += 100;
									jellyMo[p][r][0][0] = 0.01;
									//jellyMo[p][r][0][0] += (gravityZ[p][r] > 0) ? gravityZ[p][r] : -gravityZ[p][r];
								}
							}
							if( (newRigidXAngle[p][r] > 220 && newRigidXAngle[p][r] < 320) ){
								
								if(gravityX[p][r] < terminalFall  && gravityX[p][r] > -terminalFall ){
									if(newRigidXAngle[p][r] < 270){
										gravityX[p][r] += gravIncrease;
									}else{
										gravityX[p][r] -= gravIncrease; 
									}
									if(gravityMo[p][r] > 3){
										gravityMo[p][r] -= 2;
									}
								}
							}else {
								gravityMo[p][r] += 0.075 ;
	
								if((rigidXAngle[p][r] - newRigidXAngle[p][r] < 60) && rigidXAngle[p][r]- newRigidXAngle[p][r] > -60){
									//gravityZ[p][r] = 0;
									//gravityX[p][r] = 0;
									jellyPrio[p][r] += 100;
									jellyMo[p][r][0][0] = 0.01;
									//jellyMo[p][r][0][0] += (gravityX[p][r] > 0) ? gravityX[p][r] : -g ravityX[p][r];
								}
							}
					//}else{
					//	jellyMo[p][r][0][0] = 0;
						
						
					//	rigidFall[p][r] = 0;
					//	gravityMo[p][r] = 1;
					//}
					
				}

				if(jellyCollision[r] != coll && handCollided){
							jellyMo[p][r][0][0] = 0.15;
							jellyPrio[p][r] += 0.4;
							mapCollisionCounter[r] = false;
						}
						jellyCollision[r] = coll;

				if(amountOnFloor > (ballJSize[p][r]/rigidIncrement[p][r])){
					jellyMo[p][r][0][0] = 0;
				//	stopTimer[p][r] ++;
				}
				
				
				//if(amountOnFloor > (ballJSize[p][r]/rigidIncrement[p][r])/1000){
						float rotationSpeed = 1;
							
							if (!(gravityX[p][r] > 0.04 || gravityZ[p][r] > 0.04)){
								jellyMo[p][r][0][0] = 0;
			
							}
							
							rigidY[p][r] = rigidY[p][r] + (2* rigidFall[p][r]) * sin(-90 * (3.14159 / 180));
							if(rigidZAngle[p][r] - rotationSpeed  > newRigidZAngle[p][r]){ //rotate the angle slowly for effect, into the collision angle
								rigidZAngle[p][r] -= (rotationSpeed);
							}else if(rigidZAngle[p][r] + rotationSpeed< newRigidZAngle[p][r]){
								rigidZAngle[p][r] += (rotationSpeed);
							}
							

							
							if(rigidXAngle[p][r] -rotationSpeed > newRigidXAngle[p][r]){ //also rotate the x angle slowly for effect, into the collision angle.
								rigidXAngle[p][r] -=  ( rotationSpeed);
							}else if(rigidXAngle[p][r] + rotationSpeed  < newRigidXAngle[p][r]){
								rigidXAngle[p][r] += (rotationSpeed);
							}

				//	}else{
					//	bool foundFloor = findFloor(collidingO[r]);
				//		if(!foundFloor){
							if(rigidFall[p][r] != 0){
								//if(hitGround){
									rigidY[p][r] = rigidY[p][r] + (2 * rigidFall[p][r]) * sin(-90 * (3.14159 / 180)); // gravity
									if(rigidFall[p][r] < 6){ //2 is terminal velocity
										rigidFall[p][r] += 0.1; //increase until terminal velocity.
									}
								//}
							}
						//}
				//	}
				
				if((jellyMo[p][r][0][0] > 0.05 || gravityX[p][r] > 0.04 || gravityZ[p][r] > 0.04 )) {
					
					if(jellyMo[p][r][0][0] < velocity ){
						jellyMo[p][r][0][0] += 0.05;
					}
				/*	if(collidingI == -1 && divider[r] < 2){ //last perfect collision counter
								rigidZ[p][r] += (rigidZ[p][r] - (ballHeight/2)) - (obsticleZ[collidingI] - (obsticleSize[collidingI]/2))/(divider[r]); //push the object out of the obsticle. can't be done in for loop. So a counter is created on collision
								rigidY[p][r] -= (beforeFall)/2;
								rigidX[p][r] += (rigidX[p][r] - (ballHeight/2)) - (obsticleX[collidingI] - (obsticleSize[collidingI]/2))/(divider[r]);
							}
							if(collidingO[r] == -1){ //last perfect collision counter
								rigidZ[p][r] += ((rigidZ[p][r] - (ballHeight/2)) - (rigidZ[p][collidingO[r]] - (ballHeight/2)))/((5)/2); //push the object out of the obsticle. can't be done in for loop. So a counter is created on collision
								rigidY[p][r] -= (beforeFall)/2;
								rigidX[p][r] += ((rigidX[p][r] - (ballHeight/2)) - (rigidX[p][collidingO[r]] - (ballHeight/2)))/((5)/2);
							}*/
				 //if the model still has momentum
					mapCollisionCounter[r] = false;
					/*if(newRigidXAngle[p][r] != rigidXAngle[p][r]){ //move the object on it's angles, as fast as it's momentum, every loop. 
						rigidX[p][r] = rigidX[p][r] + (((slip*1 + gravityX[p][r]))/sticky) * cos(newRigidXAngle[p][r] * (3.14159 / 180));
						rigidX[p][r] = rigidX[p][r] - (gravityX[p][r]) * cos(0 * (3.14159 / 180));
						//if(bounce > 0 && !iceMode){

							rigidY[p][r] = rigidY[p][r] + ((bounce*slip*(jellyMo[p][r][0][0]/2))/sticky) * sin(rigidYAngle[p][r]* (3.14159 / 180));
						//}
					}
					if(newRigidZAngle[p][r] != rigidZAngle[p][r]){
						
						rigidZ[p][r] = rigidZ[p][r] - (gravityZ[p][r]) * cos(0 * (3.14159 / 180));
					}*/
					rigidZ[p][r] = rigidZ[p][r] + (gravityZ[p][r]) * cos(newRigidZAngle[p][r] * (3.14159 / 180));
					rigidX[p][r] = rigidX[p][r] + (gravityX[p][r]) * cos(newRigidXAngle[p][r] * (3.14159 / 180)); 
					float rotationSpeed = 10;
					
					if(rigidZAngle[p][r] - rotationSpeed  > newRigidZAngle[p][r]){ //rotate the angle slowly for effect, into the collision angle
								rigidZAngle[p][r] -= jellyMo[p][r][0][0]  * (50/gravityMo[p][r]);
							}else if(rigidZAngle[p][r] + rotationSpeed< newRigidZAngle[p][r]){
								rigidZAngle[p][r] +=  jellyMo[p][r][0][0] * (50/gravityMo[p][r]);
							}
							

							
							if(rigidXAngle[p][r] -rotationSpeed > newRigidXAngle[p][r]){ //also rotate the x angle slowly for effect, into the collision angle.
								rigidXAngle[p][r] -=  jellyMo[p][r][0][0] * (50/gravityMo[p][r]);
							}else if(rigidXAngle[p][r] + rotationSpeed  < newRigidXAngle[p][r]){
								rigidXAngle[p][r] +=  jellyMo[p][r][0][0] * (50/gravityMo[p][r]);
							}
				
				}else if((hitGround[r]) && newRigidXAngle[p][r] != 0 && newRigidZAngle[p][r] != 0 || amountOnFloor > (ballJSize[p][r]/10)){

					//	stopTimer[p][r] ++;
						//gravityX[p][r] = 0;
						//gravityZ[p][r] = 0;
						//rigidFall[p][r] = (rigidFall[p][r]/2);
						//jellyPrio[p][r] += 100;
					
					
				}
				
					
			}else if(stopTimer[p][r] > stopMax){
					//cout << "should stop" << endl;
					//if(!hitGround[r] && collidingO[r] == -1  && newRigidZAngle[p][r] != 0){
					//	rigidFall[p][r] = 0.005;
					//}
					jellyMo[p][r][0][0] = 0;
					gravityMo[p][r] = 0;
					// gravityX[p][r] = 0;
					//gravityZ[p][r] = 0; 
					
					//if(!hitGround[r] && collidingO[r] == -1 ){
								//if(hitGround){
									rigidY[p][r] = rigidY[p][r] + (2 * rigidFall[p][r]) * sin(-90 * (3.14159 / 180)); // gravity
									if(rigidFall[p][r] < 6){ //2 is terminal velocity
										rigidFall[p][r] += 0.1; //increase until terminal velocity.
									}
								//}
						//	}
					
				}


		}
		}
		else if (jellyTime && robotFalling && cubeTime){
			
			for(int r = 1; r < jellySize; r++){
				
				jellyMo[p][r][0][0]-=0.001;			

				int amountOnFloor = 0;

				for(int i = 0; i < ballJSize[p][r]; i+=rigidIncrement[p][r]){
					
					for(int v = 0; v < 3; v++){
						if(jellyMo[p][r][i][v] > 0.005){
							
							jellyMo[p][r][i][v] = jellyMo[p][r][0][0];
						}
						if(jellyMo[p][r][i][v] < 0.005){
							newRigidXAngle[p][r] = rigidXAngle[p][r];
							newRigidZAngle[p][r] = rigidZAngle[p][r];
							//rigidFall[p][r] = 0;
						}
							
						int type = v;

						
						float xRadians = rigidXAngle[p][r];
						float zRadians = rigidZAngle[p][r];
						float intX =  Balls1[type][r][i][0];
						float intY =  Balls1[type][r][i][1];
						float intZ =  Balls1[type][r][i][2];
						intX *= ballHeight;
						intY *= ballHeight;
						intZ *= ballHeight;
						//xRadians = rigidXAngle[r] * (3.14159/180);
						float x2 = cos(xRadians)*intX -sin(xRadians)*intY;
						intY = sin(xRadians)*intX +cos(xRadians)*intY;
						intX = x2;
						//zRadians = rigidZAngle[r] * (3.14159/180);
						float z2 = cos(zRadians)*intZ -sin(zRadians)*intY;
						intY = sin(zRadians)*intZ +cos(zRadians)*intY;
						
						
						intZ = z2;
						intY += rigidY[p][r];
						intX += rigidX[p][r];
						intZ += rigidZ[p][r];
						bool doneMoved = false;

					for (int o = 0; o < jellySize; o++) {
							float x2 = rigidX[p][o];
							float y2 = rigidY[p][o];
							float z2 =  rigidZ[p][o];


							if (o != r) {
									float differenceX = intX - x2;
									float differenceZ = intZ - z2;
									float differenceY = intY - y2;
									if(differenceX * differenceX < 5 && differenceZ * differenceZ < 5 && differenceY* differenceY < 5 ){
									if(collision(intX, intY, ballHeight, x2, y2, ballHeight)){
										if(collision(intZ, intY, ballHeight, z2, y2, ballHeight)){
											if(jellyPrio[p][o] > jellyPrio[p][r]){
												//if(!mapCollisionCounter[r]){
												amountOnFloor+=1;
												//jellyMo[p][r][0][0] -= 0.001;


												//if(ay > - 100 || ay < -60){
													
												float a = (atan2(y2 - intY, x2- intX));
												float az = (atan2(y2- intY, z2 - intZ));
												float ay = (atan2(y2, intY) *180/3.14159);
												rigidY[p][r] = rigidY[p][r] + ((intY - y2 + (ballHeight/2))/10);
						
														if(newRigidZAngle[p][r] != 0){
															float zIncrement =  (rigidZAngle[p][r] - az)/(200 * (jellyMo[p][r][0][0]*2));
															float xIncrement =  (rigidXAngle[p][r] - a)/(200 * (jellyMo[p][r][0][0]*2));
															if(rigidX[p][r]- rigidX[p][o] > 0){
																rigidX[p][r] -= xIncrement;
															}else{
																rigidX[p][r] += xIncrement;
															}
															if(rigidZ[p][r]- rigidZ[p][o] > 0){
																rigidZ[p][r] -= zIncrement;
															}else{
																rigidZ[p][r] += zIncrement;
															}
														}
														 jellyMo[p][r][0][0] = jellyMo[p][o][0][0] - 0.001;
														 newRigidXAngle[p][r] = 180 - newRigidXAngle[p][o];
														 newRigidZAngle[p][r] = 180 - newRigidZAngle[p][o];
		
															rigidFall[p][r] = 0.0001;
			
														//	}
															Balls1[type][r][i][0] += (slip * jellyMo[p][r][i][type]) * cos((newRigidXAngle[p][r]* (180 / 3.14159)));
															Balls1[type][r][i][2] += (slip * jellyMo[p][r][i][type]) * cos((newRigidZAngle[p][r]* (180 / 3.14159)));

														jellyPrio[p][r] += 0.3;
														jellyPrio[p][o] += 0.3;
														
														doneMoved = true;
														if(!mapCollisionCounter[r]){
															for(int c = i; c < i + rigidIncrement[p][r]; c++){

																float increase = 2;
																for(int cv = 0; cv < 4; cv++){
															
																	Balls1[cv][r][c][0] += (divider[r]*0.005*increase) * cos(newRigidXAngle[p][r]);
																	Balls1[cv][r][c][1] += (divider[r]*0.005*increase) * sin(newRigidXAngle[p][r]);
																	Balls1[cv][r][c][2] += (divider[r]*0.005*increase) * cos(newRigidZAngle[p][r]);
																		
																		
																	Balls1[cv][r][c][0] -= (Balls1[cv][r][c][0] - oldBalls1[cv][r][c][0])/divider[r];
																	Balls1[cv][r][c][1] -= (Balls1[cv][r][c][1] - oldBalls1[cv][r][c][1])/divider[r];
																	Balls1[cv][r][c][2] -= (Balls1[cv][r][c][2] - oldBalls1[cv][r][c][2])/divider[r];

																}
															}
															
														}

											o = jellySize;
											}
										
										
									}
								}
									}
									//}
							}
					
					}	
						float* angle = getCollidingAngle(intX, intY, intZ, ballHeight);
						if(angle[0] != -1){

							xrDirection[p][r] = !xrDirection[p][r];

							newRigidZAngle[p][r] = angle[1] - 180;
	
							rigidFall[p][r] = 0.0001;
							jellyPrio[p][r] += 0.3;
							if(!mapCollisionCounter[r]){
													for(int c = i; c < i + rigidIncrement[p][r]; c++){
												//if(c != i){
														float increase = 2;
														for(int cv = 0; cv < 3; cv++){
													
															Balls1[cv][r][c][0] += (divider[r]*0.005*increase) * cos(newRigidXAngle[p][r]);
															Balls1[cv][r][c][1] += (divider[r]*0.005*increase) * sin(newRigidXAngle[p][r]);
															Balls1[cv][r][c][2] += (divider[r]*0.005*increase) * cos(newRigidZAngle[p][r]);
																
																
															Balls1[cv][r][c][0] -= (Balls1[cv][r][c][0] - oldBalls1[cv][r][c][0])/divider[r];
															Balls1[cv][r][c][1] -= (Balls1[cv][r][c][1] - oldBalls1[cv][r][c][1])/divider[r];
															Balls1[cv][r][c][2] -= (Balls1[cv][r][c][2] - oldBalls1[cv][r][c][2])/divider[r];

													}

												
											}
												
											}
					}
					delete angle;
		
						
						
						
						
					}

				}
				

					mapCollisionCounter[r] = false;
					if(rigidFall[p][r] != 0){
					rigidY[p][r] = rigidY[p][r] + (2 * rigidFall[p][r]) * sin(-90 * (3.14159 / 180));
						if(rigidFall[p][r] < 2){
							rigidFall[p][r] += 0.1;
						}
					}
					if(newRigidXAngle[p][r] != rigidXAngle[p][r]){
						rigidX[p][r] = rigidX[p][r] + (jellyMo[p][r][0][0]) * cos(newRigidXAngle[p][r] * (3.14159 / 180));
						rigidY[p][r] = rigidY[p][r] + (bounce* jellyMo[p][r][0][0]) * sin(newRigidXAngle[p][r] * (3.14159 / 180));

					}
					if(newRigidZAngle[p][r] != rigidZAngle[p][r]){
						rigidZ[p][r] = rigidZ[p][r] + (jellyMo[p][r][0][0]) * cos(newRigidZAngle[p][r] * (3.14159 / 180));
					}

				

					float rotationSpeed = 1;
					if(stickIt){
						rotationSpeed = 0.1;
					}

						
							if(rigidZAngle[p][r] - rotationSpeed  > newRigidZAngle[p][r]){
								rigidZAngle[p][r] -= 2;
							}else if(rigidZAngle[p][r] + rotationSpeed< newRigidZAngle[p][r]){
								rigidZAngle[p][r] += 2;
							}
	
							
							if(rigidXAngle[p][r] -rotationSpeed > newRigidXAngle[p][r]){
								rigidXAngle[p][r] -=  2;
							}else if(rigidXAngle[p][r] + rotationSpeed  < newRigidXAngle[p][r]){
								rigidXAngle[p][r] +=  2;
							}

						
					
				}

		}
		
		
		
		if (divisionTime && robotFalling){ //breakable physics
			
			for(int r = divisionSplit; r < divisionEnd; r++){// how many models there are

				if(jellyMo[p][r][0][0] > 0.005){
					 jellyMo[p][r][0][0] -= 0.005; //decrease momentum
				}
				
				for(int frags = 0; frags < splitSize[r]+1; frags++){ // there are 
				
					int amountOnFloor = 0;
					if(!mapCollisionCounter[r]){
					
					bool colliding = false;
					int collidingIP = 0;

				for(int sp =0; sp < splitCounter[r][frags]; sp+=rigidIncrement[p][r]){ // increment ten for performance splitCounter frags gives the relative point fr the incremement of fragments of a model. 
					if(sp < ballJSize[p][r]){


						int type = 0;
						
						
						float x = Balls1[type][r][splitFrag[r][frags][sp]][0]; //get the x , y, z
						float y = Balls1[type][r][splitFrag[r][frags][sp]][1];
						float z = Balls1[type][r][splitFrag[r][frags][sp]][2];
						
						x *= ballHeight; //scale them
						y *= ballHeight;
						z *= ballHeight;

						float* results = rotateXZ(x, y, z, smashXAngle[r][frags], smashZAngle[r][frags]);  // rotate x and z
						x =  results[0];
						y =  results[1];
						z =  results[2];
						delete results;		
								
					
						y += smashY[r][frags]; //translate

						x += smashX[r][frags];
						z += smashZ[r][frags];
						if(jellyTime){
							for (int o = 0; o < jellySize; o++) {

									float x2 = rigidX[p][o];
									float y2 = rigidY[p][o];
									float z2 = rigidZ[p][o]; //simple collision for performance
									
									x2 *= ballHeight;
									y2 *= ballHeight;
									z2 *= ballHeight;

									if (o != r) {
										
										float* angle2 = getCustomCollidingAngle(x, y, z, x2, y2, z2, ballHeight); //get a collision
										if(angle2[0] != -1){
											amountOnFloor++;

													smashNewZAngle[r][frags] = (angle2[1] - 180); //get the opposite angles

													smashNewXAngle[r][frags] = (angle2[0] - 180);
													
													smashX[r][frags] = smashX[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewXAngle[r][frags]* (3.14159/180))); //move the fragment away from the collision
													smashZ[r][frags] = smashZ[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewZAngle[r][frags]* (3.14159/180)));
													smashY[r][frags] = smashY[r][frags] + (jellyMo[p][r][0][0]) * sin((smashNewXAngle[r][frags]* (3.14159/180)));

										}
										delete angle2;

									}
								//}
							}
						}
						if(fabricTest){
							int increment = 2;
							for(int f = 0; f < fabricSize; f+= increment){
								increment = rand() % 4 + 1;
								float x2 = Balls1[0][0][f][0];
								float y2 = Balls1[0][0][f][1];
								float z2 = Balls1[0][0][f][2];
								float* angle2 = getCustomCollidingAngle(x, y, z, x2, y2, z2, ballHeight);
								if(angle2[0] != -1){
											if(jellyMo[p][r][0][0] > 0.1){
												Balls1[0][0][f][1] -= (ballHeight/4);
											}
											smashNewZAngle[r][frags] = (angle2[1] - 180); //get the opposite angles

													smashNewXAngle[r][frags] = (angle2[0] - 180);
													
													smashX[r][frags] = smashX[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewXAngle[r][frags]* (3.14159/180))); //move the fragment away from the collision
													smashZ[r][frags] = smashZ[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewZAngle[r][frags]* (3.14159/180)));
													smashY[r][frags] = smashY[r][frags] + (jellyMo[p][r][0][0]) * sin((smashNewXAngle[r][frags]* (3.14159/180)));

								}	
								delete angle2;
							}
							
						}
						for (int o = divisionSplit; o < divisionEnd; o++) {
							for( int frag = 0; frag < splitSize[o]+1; frag++){
								float x2 = smashX[o][frag];
								float y2 = smashY[o][frag];
								float z2 = smashZ[o][frag];


								if (o != r) {
									float* angle2 = getCustomCollidingAngle(x, y, z, x2, y2, z2, ballHeight); //get a collision
										if(angle2[0] != -1){
												amountOnFloor++;
												smashX[r][frags] = smashX[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewXAngle[r][frags]* (180 / 3.14159)));
												smashZ[r][frags] = smashZ[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewZAngle[r][frags]* (180 / 3.14159)));
												smashY[r][frags] = smashY[r][frags] + (jellyMo[p][r][0][0]) * sin((smashNewXAngle[r][frags]* (3.14159/180)));
																
			
												smashNewZAngle[r][frags] = (angle2[1] - 180);
				
												smashNewXAngle[r][frags] = (angle2[0] - 180);
	
												
										}

											delete angle2;

								}
							}
						}

						if(cogs){ //check against the cogs
							for(int c =0; c < cogSize; c++){
								for(int o = cogLength[c]; o < cogLength[c+1]; o++){
									
									float* angleR = getCustomCollidingAngle(x, y, z, obsticleRX[o], obsticleRY[o], obsticleRZ[o], ballHeight); //get colliding angle from cogs
									if(angleR[0] != -1){
										xrDirection[p][r] = !xrDirection[p][r]; //shake to get into a bettre positioning
										smashNewXAngle[p][r] = (angleR[0] - 180); //opposite angle
										if(!xrDirection[p][r]){
											smashNewXAngle[p][r] = (180 - angleR[0]); //opposite of opposite angle
										}
										zrDirection[p][r] = !zrDirection[p][r];
										smashNewZAngle[p][r] = (angleR[1] - 180);
										if(!zrDirection[p][r]){
											smashNewZAngle[p][r] = (180 - angleR[1]);
										}

										smashFall[r][frags]  = 0.0001; //stop gravity
										jellyPrio[p][r] += 0.3; //increase priority
										jellyMo[p][r][0][0] = 0.2;

										smashX[r][frags] = smashX[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewXAngle[r][frags]* (3.14159/180))); //move in angle direction using momentum
										smashZ[r][frags] = smashZ[r][frags] + (jellyMo[p][r][0][0]) * cos((smashNewZAngle[r][frags]* (3.14159/180)));
									}
									delete angleR;
								}
							}
						}


						float* angle = getCollidingAngle(x, y, z, ballHeight); //check against the colliding obsticle map
						if(angle[0] != -1){
							collidingIP = splitFrag[r][frags][sp];
							smashFall[r][frags] = 0.0001; // stop gravity
							amountOnFloor++;
							jellyPrio[p][r] += 0.1;

												
												if(!mapCollisionCounter[frags]){
													smashY[r][frags] += 0.1;
													
												}
													
													if((angle[0] > 50 && angle[0] < 130) ||(angle[1] > 50 && angle[1] < 130) ){
														if(jellyMo[p][r][0][0] > 0.1){
															jellyMo[p][r][0][0] -= 0.001; //if going up depleat momentum
														}
													}else if((angle[0] < 180 && angle[0] > 0)|| (angle[1] < 180 && angle[1] > 0)){
														if(jellyMo[p][r][0][0] > 0.1 && !mapCollisionCounter[r]){
															jellyMo[p][r][0][0] += 0.001; // if going down increase momentum
														}
													}
												
												

												smashNewZAngle[r][frags] = (angle[1] - 180); //set the opposite colliding angle
												smashNewXAngle[r][frags] = (angle[0] - 180);
												
												smashY[r][frags] = smashY[r][frags] + (jellyMo[p][r][0][0]) * sin((smashNewXAngle[r][frags]* (3.14159/180)));

												}
						delete angle;
						
						}

						
					}
				}
					if(jellyMo[p][r][0][0] > 0.05) {
						mapCollisionCounter[r] = false;
						if(smashFall[r][frags] < 2){
							smashFall[r][frags] += 0.1;
						}
						int rotationSpeed = 10;
								
							
						if(smashXAngle[r][frags] -rotationSpeed > smashNewXAngle[r][frags]){ //increment rotation smoothly to colliding angle
							smashXAngle[r][frags] -=  jellyMo[p][r][0][0] * 30;
						}else if(smashXAngle[r][frags] + rotationSpeed  < smashNewXAngle[r][frags]){
							smashXAngle[r][frags] +=  jellyMo[p][r][0][0] * 30;
						}
						
						if(smashZAngle[r][frags] -rotationSpeed > smashNewZAngle[r][frags]){
							smashZAngle[r][frags] -=  jellyMo[p][r][0][0] * 30;
						}else if(smashXAngle[r][frags]+ rotationSpeed  < smashNewZAngle[r][frags]){
							smashZAngle[r][frags] +=  jellyMo[p][r][0][0] * 30;
						}
						smashY[r][frags] = smashY[r][frags] + (2 * smashFall[r][frags]) * sin(-90 * (3.14159 / 180));
						if(smashXAngle[r][frags] != 0){
							smashX[r][frags] = smashX[r][frags] + ((jellyMo[p][r][0][0])) * cos(smashNewXAngle[r][frags] * (3.14159 / 180)); //move the objects each iteration
							smashY[r][frags] = smashY[r][frags] + ((jellyMo[p][r][0][0])) * sin(smashNewXAngle[r][frags] * (3.14159 / 180));
						//	rigidY[r] = rigidY[r] + (1 *jellyMo[r][0][0]/(divider[r]/2)) * sin(newRigidXAngle[r] * (3.14159 / 180));
						}
						if(smashZAngle[r][frags] != 0){
							smashZ[r][frags] = smashZ[r][frags] + ((jellyMo[p][r][0][0])) * cos(smashNewZAngle[r][frags] * (3.14159 / 180));
						//	rigidY[r] = rigidY[r] + (1 *jellyMo[r][0][0]/(divider[r]/2)) * sin(newRigidXAngle[r] * (3.14159 / 180));
						}
					}else{
						if(rigidY[p][r] > 20){
							mapCollisionCounter[r] = true;
						}
					}
					}
				}
				
				//int type = 0;
				
			}
			if(dominoTime){

				for(int v = 1; v < dominoCount; v++){

					if(dHitGround[v] == false && !dHitting[v]){
						dominoY[v] -= 0.6;

					}
					
					
					for(int c = 0; c < dominoVSize; c+=2){
						float x = dominoVVX[v][c]; 
						float y = dominoVVY[v][c];
						float z = dominoVVZ[v][c];
						
						if(x > kettleX - 4 && x < kettleX + 4){
							kettleBoil = true;
						}
						if(cogs){ //if colliding with cogs
							for(int c =0; c < cogSize; c++){
								for(int o = cogLength[c]; o < cogLength[c+1]; o+=3){
									
									float* angleR = getCustomCollidingAngle(x, y, z, obsticleRX[o], obsticleRY[o], obsticleRZ[o], ballHeight); //collidinh with pre rotated obsticle point
									if(angleR[0] != -1){
										if(dHitGround[v]){
															dHitting[v] = true;
		
										}
									}
									delete angleR;
									
								}
								
							}
						}
						if(marbleTime){
							for(int c = 0;   c< marbleSize; c++){
								float* angleR = getCustomCollidingAngle(x, y, z, marble[c][0], marble[c][1], marble[c][2], marbleDimensions);
								if(angleR[0] != -1 && dHitting[v] && !dHitGround[v]){
									marble[c][2] -= 4.2;
									marbleMoved = true;

								}else if(angleR[0] != -1){
									if(marbleMoved){
										dHitting[v] = true;
									}
								}
								delete angleR;
							}
						}
						for (int o = 0; o < jellySize; o++) { //check against other objects
								float x2 = rigidX[p][o];
								float y2 = rigidY[p][o];
								float z2 = rigidZ[p][o]; //simple for performance


								x2 *= ballHeight;
								y2 *= ballHeight;
								z2 *= ballHeight;
								
								

								//if (o != r) { //make sure not colliding with itself
									if(dHitGround[v]){
										float* angle2 = getCustomCollidingAngle(x, y, z, x2, y2, z2, ballHeight);
										
										if(angle2[0] != -1){
											//cout << "here: " << v << endl;
											dHitting[v] = true;
											dHitGround[v] = false; 
											//}
										}
										delete angle2;
									}
							
								}
						for(int d = v-1; d > v-3; d--){
							if(d != v){
								for(int e = 0; e < dominoVSize; e+=2){
								

									if(dHitting[d]){
	
										float* angle2 = getCustomCollidingAngle(dominoVVX[d][e], dominoVVY[d][e],dominoVVZ[d][e], x, y, z, 0.3);
										if(angle2[0] != -1){
				
															dHitting[v] = true;
															dHitGround[v] = false; 
		
										}
										delete angle2;
	
									}
					
								}
							}
						}
						
						if(!dHitGround[v]){
							float* angle = getCollidingAngle(x, y, z, 1);
							if(angle[0] != -1){
								if(!dHitting[v]){
									dominoY[v] += (dominoY[v] - obsticleY[collidingIP]);
								}
								dHitGround[v] = true;
								dHitting[v] = false;
							}
							
							delete angle;
						}
						

						
						
					}
					
				}
				
			}
			

	//}
	if(cogs){ // cog collision checking against over cogs
			for(int c = 0; c < cogSize; c++){
				for(int o = cogLength[c]; o < cogLength[c+1]; o++){
					for(int c2 = 0; c2 < cogSize; c2++){
						if(c2 != c){
							for(int r = cogLength[c2]; r < cogLength[c2+1]; r++){
								
								float* angle = getCustomCollidingAngle(obsticleRX[r], obsticleRY[r], obsticleRZ[r], obsticleRX[o], obsticleRY[o], obsticleRZ[o], obsticleSize[o]);
								if(angle[0] != -1){
									if(cogPrio[c] > cogPrio[c2]){
										//cout << "hjere" << endl;
												cogPrio[c2] += 0.001;
												cogPrio[c] += 0.002;
												if(cogLeft[c]){
													cogLeft[c2] = false;
													cogAngle[c2] += length(obsticleRX[r], obsticleRY[r], obsticleRX[o], obsticleRY[o]); //move the cog angle 
												}else{
													cogLeft[c2] = true;
													cogAngle[c2] -= length(obsticleRX[r], obsticleRY[r], obsticleRX[o], obsticleRY[o]);
												}
				
											}
									
								} 
								delete angle;
								

						}
					}
				}
			
			}
		}
	}

		//}
	
			if(cogs && cogSize > 0){
				for(int i =cogSize-1;i > cogSize-2; i--){ //cog mechanics that need to work every iteration
					cogPrio[i] += 0.002; //increase priority. 
					if(!kettleTime && !cogReaction){
						cogAngle[i]+= 4; //increase angle
					}
					cogLeft[i] = true;
					if(cogAngle[i] > 360){
						cogAngle[i] = 0;
					}
					
					
				}
				for(int c = 0 ; c < cogSize; c++){
						if(cogSpin[c] > 0){
							cogAngle[c] -= cogSpin[c];
							cogSpin[c] -= 1;
						}

						for(int v = cogLength[c]; v < cogLength[c+1]; v++){
							obsticleRX[v] = obsticleX[v];
							obsticleRY[v] = obsticleY[v];
							obsticleRZ[v] = obsticleZ[v]; //get original starting position
							
							float * results = rotateY(obsticleX[v], obsticleY[v], obsticleZ[v], cogAngle[c]); //rotate the collisions
							
							obsticleRY[v] = results[1]; //set into new variable which is going to be used.
							obsticleRX[v] = results[0];
							obsticleRZ[v] = results[2];
							
							delete results;
							
							
							obsticleRX[v] += cogX[c]; //add translation
							obsticleRY[v] += cogY[c];
							obsticleRZ[v] += cogZ[c];
							
	
						}
					}
			}
				if(dominoTime){
					for(int c = 0; c < dominoCount; c++){
						if(dHitting[c]){
							dominoAngleY[c] -= 6;
						}

							for(int v = 0; v < dominoVSize; v++){
								dominoVVZ[c][v] = dominoVZ[c][v];
								dominoVVY[c][v] = dominoVY[c][v] + dominoHeight; //get original start position
								dominoVVX[c][v] = dominoVX[c][v];

										dominoVY[c][v] += dominoHeight; //chip a bit off so the rotation origin is okay
										
	
										
										
										float* results = (float*) malloc(3 * sizeof(float));
										
										 //rotate one two axis, the order is important

										results = rotateY(dominoVVX[c][v], dominoVVY[c][v], dominoVVZ[c][v], dominoAngleY[c]);
										results = rotateX(*(results+0), *(results+1), *(results+2), dominoAngleX[c]);

										
										dominoVVZ[c][v] = (float)results[2]; //set into new variable
										dominoVVX[c][v] = (float)results[0];
										dominoVVY[c][v] = (float)results[1];
										
										delete results; //garbage collection

										dominoVY[c][v] -= dominoHeight; //put the bit back on 
										
										dominoVVZ[c][v] += dominoZ[c]; //add translation
										dominoVVY[c][v] += dominoY[c]- (dominoHeight);
										dominoVVX[c][v] += dominoX[c];
										

						}
						
					}
				}
			
		//}
	if(robot){
				if(!robotFalling){
					if(coolDown < 5){
						coolDown++;
					}else{
						if(p < 6){
							p++;
							
						}else{
							p = 0;
						}
						coolDown = 0;
					}
				}
			}
	
}

