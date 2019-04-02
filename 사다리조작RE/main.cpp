#include <stdio.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m, h;
int nCheck_Ret, nRet;
int level;
int nfiled[31][11];
int ntemp[31][11];

int check(){
	int one_line = 0;
	for (int i = 1; i <= n; i++){
		int y = 1;
		int x = i;
		while (y < h + 1){
			if (nfiled[y][x]){
				if (nfiled[y][x] == 1){
					x++; y++;
				}
				else{
					x--; y++;
				}
			}
			else{
				y++;
			}
		}
		if (x != i){
			one_line = 1;
			break;
		}
	}
	if (one_line)
		return 0;
	return 1;
}


void dfs(int crtx, int crty, int cnt)
{
	if (cnt == level){
		nCheck_Ret = check();
		if (nCheck_Ret)
			nRet = 1;
		return;
	}

	for (int i = crty; i <= h; i++){
		for (int j = 1; j < n; j++){
			if (!nfiled[i][j] && !nfiled[i][j + 1]){
				nfiled[i][j] = 1;
				nfiled[i][j + 1] = 2;
				dfs(j, i, cnt + 1);
				nfiled[i][j] = 0;
				nfiled[i][j + 1] = 0;
			}
		}
	}
}

int main()
{

	scanf("%d %d %d", &n, &m, &h);

	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= n; j++){
			nfiled[i][j] = 0;
			ntemp[i][j] = 0;
		}
	}

	int tmp_l, tmp_r;
	for (int i = 0; i < m; i++){
		scanf("%d %d", &tmp_l, &tmp_r);
		nfiled[tmp_l][tmp_r] = 1;
		nfiled[tmp_l][tmp_r + 1] = 2;
		ntemp[tmp_l][tmp_r] = 1;
		ntemp[tmp_l][tmp_r + 1] = 2;
	}
	nCheck_Ret = check();
	if (nCheck_Ret){
		printf("%d\n", 0);
		return 0;
	}

	for (int i = 1; i <= 3; i++){
		nRet = 0;
		level = i;

		for (int j = 1; j <= h; j++){
			for (int k = 1; k <= n; k++){
				nfiled[j][k] = ntemp[j][k];
			}
		}

		dfs(1, 1, 0);
		if (nRet){
			printf("%d\n", i);
			break;
		}
	}
		
	if(!nRet)
		printf("%d\n", -1);

	

	return 0;
}