#include <stdio.h>
#include <conio.h>
#include <graphics.h>
//(x2+y2-1)3+x2y3==0

#define start_k 50
#define maxk 300
int deltak = 10;
float width = 1000, height = 800;
int flag = 1;
int isfirst = 0;

void aixin(int k) {
	setlinecolor(RGB(255 - k / 1.5, 0, 0));
	float x, y, z;
	//x>-1.5 && x<1.5,y>=0 && y<1.5,z<=0 && z>=-1
	for (x = -1.139001 * k; x <= 1.139 * k; x++) {
		BeginBatchDraw();
		float x0 = x / k;
		if (x <= -k || x >= k) {
			for (y = -1.5 * k; y <= 0; y++) {
				float y0 = y / k;
				float a = x0 * x0 + y0 * y0 - 1;
				if (a * a * a + x0 * x0 * y0 * y0 * y0 <= 0) {
					break;
				}
			}
			for (z = 0; z > -0.5 * k; z--) {
				float z0 = z / k;
				float a = x0 * x0 + z0 * z0 - 1;
				if (a * a * a + x0 * x0 * z0 * z0 * z0 <= 0) {
					break;
				}
			}
		}
		else {
			for (y = -1.5 * k; y <= 0; y++) {
				float y0 = y / k;
				float a = x0 * x0 + y0 * y0 - 1;
				if (a * a * a + x0 * x0 * y0 * y0 * y0 <= 0) {
					break;
				}
			}
			for (z = k; z >= 0; z--) {
				float z0 = z / k;
				float a = x0 * x0 + z0 * z0 - 1;
				if (a * a * a + x0 * x0 * z0 * z0 * z0 <= 0) {
					break;
				}
			}
		}
		line(x + width / 2, y + height / 2, x + width / 2, z + height / 2);
	}
	FlushBatchDraw();
	Sleep(100);
}

void draw(int k /*????*/) {
	if (k > maxk) {
		flag = -flag;
		return;
	}
	if (k <= start_k && isfirst != 0) {
		flag = -flag;
		return;
	}
	if (isfirst == 0) {
		isfirst = 1;
	}
	aixin(k);
	cleardevice();
	while (1) {
		if (flag > 0) {
			draw(k + deltak);
		}
		if (flag < 0) {
			draw(k - deltak);
		}
	}
}

void startup() {
	initgraph(width, height);
	setbkcolor(BLACK);
	cleardevice();
}

int main() {
	startup();
	draw(start_k);
	_getch();
	return 0;
}