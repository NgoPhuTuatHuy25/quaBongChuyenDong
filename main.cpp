#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
void ktdh(){
	int gd=DELETE, gm;
	initgraph(&gd, &gm,"D:\\DH\\BGI");//thu muc do hoa
}
void nhap(int &x0, int &y0, int &R, int &color,int &mauto){
    cout<<"Vui long nhap vao toa do O"<<endl;
	cout<<"nhap vao x=";cin>>x0;
	cout<<"nhap vao y=";cin>>y0;
	cout<<"nhap vao R=";cin>>R;
	cout<<"nhap mau bien(tu 0-15):";cin>>color;
	cout<<"nhap mau to:";cin>>mauto;
}
//ve doi xung 8 diem trong duong tro
void ve8diem(int x0, int y0, int x,int y, int color){
	putpixel(x+x0, y+y0,color);
	putpixel(y+x0, x+y0,color);
	putpixel(-x+x0, -y+y0,color);
	putpixel(-y+x0, -x+y0,color);
	putpixel(-x+x0, y+y0,color);
	putpixel(-y+x0, x+y0,color);
	putpixel(x+x0, -y+y0,color);
	putpixel(y+x0, -x+y0,color);
}
///thuat toan lam tron
void lamtronso(int x0,int y0,int R, int color){
    int x,y;
    x=0;y=R;
    while(x<=y){
        y=round(sqrt(R*R-x*x));
        ve8diem(x0,y0,x,y,color);
        x++;
    }
}
///thuat toan midpoint
void midpoint(int x0, int y0,int R, int color){
	int x=0, y =R;
	float P= 5/4-R;
	ve8diem(x0,y0,x,y,color);
	while(x<=y){
		if(P<0) P+=2*x+3;
		else{
			y--;
			P+=2*(x-y)+5;
		}
		x++;
		ve8diem(x0,y0,x,y,color);
	}
}
//thuat toan bresenham
void bresenham(int x0, int y0, int R, int color){
	int x= 0, y = R;
	float P= 3-2*R;
	cout<<P;
	while(x<=y){
		ve8diem(x0, y0, x, y, color);
		x++;
		delay(15);
		if(P<0){
			P+=4*x + 6;
		}
		else{
			y--;
			P+=4*(x-y) + 10;
		}
	}
}
void dichuyen(int &y0,int &dy){
	if( y0 + dy > getmaxy()-100 || y0+dy<100){///khoảng cách biên của trục tọa độ(y, -y)
        dy =-dy;
    }
    y0+=dy;
}
void paint(int x0, int y0, int R, int color, int mauto){
    setcolor(mauto);
    setfillstyle(SOLID_FILL, mauto);
    fillellipse(x0, y0, R, R);
    midpoint(x0, y0, R, color);
    midpoint(x0, y0, R-1, color);
    midpoint(x0, y0, R-2, color);
    //lamtronso(x0, y0, R, color);
    //bresenham(x0, y0, R, color);
}
///di chuyển up, down, right, left
void docphim(int &x0, int &y0, int &R, int &color, int &mauto){
	int getch();
	while(1){
		char key = getch();
		if(key==KEY_RIGHT){
			x0+=50;
		}else if(key==KEY_LEFT){
			x0-=50;
		}else if(key==KEY_UP){
			y0-=50;
		}else if(key==KEY_DOWN){
			y0+=50;
		}
		clearviewport();
		paint(x0,y0, R, color, mauto);
	}
}
void xulysukien(int &x0, int &y0, int &R, int &color, int &mauto){
	int value;
	cout<<"So can nhap = ";
	cin>>value;
	if(value==1){
		nhap(x0, y0, R, color, mauto);
		paint(x0,y0, R, color, mauto);
		docphim(x0, y0, R, color, mauto);
	}
	if(value==2){
    	int dy=10;
    	int t=50;
    	x0 = 300, y0 = 200, R=50;
		while(1){
        	dichuyen(y0, dy);
        	paint(x0,y0, R, 9, 10);
        	delay(t);
        	//t++;
        	dy++;///chuyển động nhanh dần đều
        	clearviewport();
		}
	}
}

int main(){
	ktdh();
	int x0, y0, R, color, mauto;
    cout<<"Vui long nhap 1 & 2!"<<endl;
	cout<<"Nhap 1 de ve"<<endl;
	cout<<"Nhap 2 chuyen dong len xuong" <<endl;
	xulysukien(x0, y0, R, color, mauto);
	closegraph();
	getch();
	return 0;
}
