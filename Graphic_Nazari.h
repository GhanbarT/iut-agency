
void InitCanvas(int cx,int cy);
void SetBkColor(int r,int g,int b);
void ResetCanvas();

//void DrawTriangle(int c,int x1,int x2,int x3,int y1,int y2,int y3,int z1=0,int z2=0,int z3=0);
void DrawLine(int c,int x1,int x2,int y1,int y2,int z1,int z2);
//void DrawPoint(int c,int x,int y,int z=0);
void DrawText1(int x,int y,int c,char *txt);
void DrawBMP(int x,int y,int index);

void DrawCanvas();

void ReadXYpos(int *x,int *y,int *MouseFlag);