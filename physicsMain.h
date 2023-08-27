
#ifndef PHYSICSMAIN_H
#define PHYSICSMAIN_H

#include "physicsLevel.h"
#include "GL/glu.h"
#include <GL/gl.h>



class physicsMain{
	public:
	
	
		bool showTable = false;
	
		void initModelPhysics();
		void initPhysics(bool load);
		void setObsticleCollisions(bool flat);
		void runPhysics();
		void setHand(float x, float y, float z);
		void drawScene();
		void cleanObjects();
		void setBreak(void);
		void setHard(void);
		void setFabric(void);
		void setSoft(void);
		bool isModel(void);
		void dropModel(void);
		void setCoords(float x, float y, float z);
		void setIce(bool setter);
		void setSticky(bool stickEr);
		void setCogs(bool set);
		void setCogReaction(bool set);
		void setRobot();
		void setRag();
		void LoadMap(bool show, const char* filename);
		void LoadBodies(char* folder);
		void setSplit(int value);
		float getBalls(int l, int r, int i, int v);
		int getJellySize();
		int getballj(int r);
		float* getRigid(int r);
		float* getRotation(int r);
		float* getBallColor(int r);
		void setScale(float amount);
		float getScale();
		void process(int gradient);
		void setAmount(int amount);
		bool robot = false;
		bool cubeTime = false;
		void setMarbleSpawn(float x, float y, float z);
		void flatSurface();
		void setCubeTime(bool getter);
		bool isFabric(void);
		bool isDomino(void);
		void runDomino(void);
		void moveFabricY(void);
		void moveFabricX(int value);
		void rotateFabric(void);
		bool isFabricTest();
		void loadHand();
		void moveTestX(int value);
		void setSoftGradient(float div);
		void initDomino(int angle, bool turn);
		void loadRope();
		void randomMap(void);
		void testMap(void);
		bool isMarble(void);
		void resetDomino(void);
		void setDominoGap(float x, float y, float z);
		void setFabricCoords(float x, float y, float z);
		float* rotateX(float &valueX, float &valueY, float &valueZ, float angleX);
		float* rotateZ(float &valueX, float &valueY, float &valueZ, float angleZ);
		float* rotateY(float &valueX, float &valueY, float &valueZ, float angleY);
		float* getCollidingAngle(float &x, float &y, float &z, float dimensions);
		
		float* getRobotCollidingAngle(float &x, float &y, float &z, float dimensions);
		void TamperJelly(float increase, float angleX, float angleY, float angleZ, int gradient, int start, int r);
		//void sortFluid(int counter);
		void restoreFromJelly(int gradient, int start, int r);
		float* rotateXZ(float &valueX, float &valueY, float &valueZ, float angleX, float angleZ);
		float* getCustomCollidingAngle(float x, float y, float z, float x2, float y2, float z2, float dimensions);
		void updateFaces(int start, int r);
		void setRigidSplit(int split);
		void resetPhysics(void);
		float getGradient();
		float largestX[200];
		float smallestBX[200];
		float largesBY[200];
		void setFabricTest();
		float smallesBY[200];
		float largestBZ[200];
		float smallestBZ[200];
		void setHeat(bool value);
		int getProcess();
		void letGo();
		void moveRopeX(float value);
		void setDominoCoords(float x, float y, float z);
		bool isRope(void);
		void setFalling(void);
		void setMelting(void);
		bool getHand(void);
		void moveHandX(float value);
		void moveHandY(float value);
		void setVelocity(float vel);
		int getSize();
		float getVelocity(void);
		void initFluid();
		void setHands(int counter, float x, float y, float z);
		void LoadMapWithSkewArray(float x, float y, float z, int index, float size );
		void setWood(float* X, float* Y, int size);
		void setGrass(float* X, float* Y, int size);
		void setDirt(float* X, float* Y, int size);
		void setStone(float* X, float* Y, int size);
		void SetObsticleLength(int max);
		void setHandCounter(int count);
		void initMarble();
		physicsMain() {     // Constructor
		  sphere = gluNewQuadric();
		}
	private:
		physicsLevel levelLoad;
		GLUquadric* sphere;
		void initRigid();
		void sortByX(int r);
		void bubbleSortObsticle();
		void swap(float *xp, float *yp);
		void swapFace(int *xp, int *yp);
		bool collision(float p1x, float p1y, float r1, float p2x, float p2y,  float r2);
		//void updateFaces(int face1, int counter, float x, float y, float z, int r);
		float length(float x, float y, float x2, float y2);
		void processEfficient();
		void processNeutral();
		void UpdateFace(int c, int r);
		
		void material(int dlist, GLfloat * ambient, GLfloat * diffuse, GLfloat * specular, GLfloat shininess);
		float get_random(void);
		GLfloat emerald_shininess = 76.8;
		float ballHeight = 1;
		int collidingI = -1;
		int ballColours[1000];
		int coolDown = 0;
		bool mapCollisionCounter[1000];
		float dropX = 10;
		float dropY = 0;
		float dropZ = 5;
		
		float dominoSX;
		float dominoSY;
		float dominoSZ;
		
		float weight[200];
		int pin;
		float divider[200];
		bool fabricColliding[500];
		int ballSize = 50;
		bool fabricRipping = false;
		int ripCounter = -1;
		int p = 0;
		
		bool handTime = false;
		float handX[15];
		float handY[15];
		float handZ[15];
		int handCount;
		int rigidSize = 1;
		int frameNumber[200];
		float rigidX[10][200];
		float rigidY[10][200];
		float rigidZ[10][200];
		float rigidZAngle[10][200];
		float rigidXAngle[10][200];
		float rigidYAngle[10][200];
		float rigidFall[10][200];
		bool xrRotation[10][200];
		bool zrRotation[10][200];
		bool xrDirection[10][200];
		bool zrDirection[10][200];
		bool rxSet[200];
		bool rzSet[200];
		float fakeMo[200];
		float rigidSpeed = 1;
		float newRigidXAngle[10][200];
		float newRigidZAngle[10][200];
		float fallIncrement[200];
		float Mo[200];
		int fabricSize;
		bool oldXSet[1000];
		float ballSpeed[1000];
		
		float handRX[1000];
		float handRY[1000];
		float handRZ[1000];
		int handCounter;
		
		float robotSkew;
		
		
		
		int processGradient = 1;
		
		bool boxMode = false;
		bool wind = false;
		bool jellyTime = false;
		bool rigidBody = false;
		bool divisionTime = false;
		bool fabricTime = false;
		bool customObject = true;
		bool robotFalling = true;
		bool meltingTime = false;
		bool fluidTime = false;
		bool collidedM[200][2000];
		bool cogs = false;
		bool ragdoll = false;
		bool iceMode = false;
		bool dominoTime = false;
		bool cogReaction = false;
		bool ballPond = false;
		bool fabricTest = false;
		
		bool kettleTime = false;
		bool kettleBoil = false;

		
		float kettleSX;
		float kettleSY;
		float kettleSZ;

		float kettleX;
		float kettleY;
		float kettleZ;

		float kettleScale[200];
		
		float heatColour[200][3000][3];
		bool heatMap = false;
		bool getStats[200];
		bool statTime;
		
		bool ropeTime = false;
		
		int ropeCounter = 0;
		int rigidTop; 
		int ripCount = 0;
		int rip[10];
		
		float ropeX[200];
		float ropeZ[200];
		float ropeY[200];
		float ropeAngle[200];
		float ropeFriction[200];
		int ropeSize; 
		bool ropeDirection[10];
		float oldRopeAngle[200];
		float addedSpeed;
		float ropeLastX[10];
		float ropeLastY[10];
		float ropePrio[10];
		float ropeMoX;
		bool holdingRope = false;
		float ropeDimensions;
		
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
		
		int dominoCount;
		int dominoCounter;
		float currentDominoAngle;

		float slip = 1;
		int stick = 180;
		int bounce = 0;
		bool hitGround[200];
		float cogX[10];
		float cogY[10];
		float cogZ[10];
		float cogSpin[10];
		float obsticleRX[10000];
		float obsticleRY[10000];
		float obsticleRZ[10000];
		int cogSize = 0;
		float cogAngle[10];
		int cogFSize = 0;

		float obsticleX[20000];
		float obsticleY[20000];
		float obsticleZ[20000];
		float obsticleSize[20000];
		int obsticleCounter =2;
		char obsticleType[20000];

		float fabricAngle[2000];
		float fabricAngleZ[2000];
		int fluidSize;
		
		float fabricY;
		float fabricZ;
		float fabricX;
		
		bool fabricFinished = false;

		float smashXAngle[200][6];
		float smashZAngle[200][6];
		float smashFall[200][6];
		float smashX[200][6];
		float smashZ[200][6];
		float smashY[200][6];
		float smashNewXAngle[200][6];
		float smashNewZAngle[200][6];

		int ballFaces[200][3000][4];


		float ballMo[1000];
		float fallMo[1000];


		float marble[200][3];

		float marbleAngle[200][2];
		
		bool marbleMoved;
		float marbleFall[200];
		float marbleMo[200];
		float marbleDimensions;
		int constJelly[200][100];
		
		int divisionSplit;
		int divisionEnd;
		int divisionSize;

		bool marbleTime = false;


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
		int ouraFace[200][3000][10][4];
		int ouraFaces[200][3000][10][4];
		int ouraFaceCounter[200][3000][4];
		float Balls1[4][200][3000][3];
		int waitJ[200];
		float oldBalls1[4][200][3000][3];
		float BallNormals[200][3000][3];
};
#endif