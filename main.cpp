#include <algorithm>
#include <iostream>
#include <limits>

int fn_MinDis(int* ip_Dist, bool* bp_SptSet, int i_Size){
	int i_Min = std::numeric_limits<int>::max();
	int i_MinInd = 0;

	for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
		if (bp_SptSet[i_Ct] == false &&
            ip_Dist[i_Ct] <= i_Min){

            i_Min = ip_Dist[i_Ct];
            i_MinInd = i_Ct;
		}
	}
	return i_MinInd;
}

void fn_ShowSol(int* ip_Dist, int i_Size){
	//std::cout<< ip_Dist[i_Size-1];
	for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
        std::cout<< ip_Dist[i_Ct] << " ";
	}
}

void fn_Dijkstra(int** i2p_2DMap, int i_SrcInd, int i_Size){
	int ia_Dist[i_Size];
	bool ba_SptSet[i_Size];

	std::fill(ia_Dist, ia_Dist+ i_Size, std::numeric_limits<int>::max());
	std::fill(ba_SptSet, ba_SptSet+ i_Size, false);

	ia_Dist[i_SrcInd] = 0;
    fn_ShowSol(ia_Dist, i_Size);
    std::cout<< "\n";
	for (int i_Ct= 0; i_Ct < i_Size - 1; i_Ct++) {
		int i_MinInd = fn_MinDis(ia_Dist, ba_SptSet, i_Size);
		ba_SptSet[i_MinInd] = true;

		for (int i_Ct2 = 0; i_Ct2 < i_Size; i_Ct2++){
            if (!ba_SptSet[i_Ct2] && i2p_2DMap[i_MinInd][i_Ct2] > 0 &&
                 ia_Dist[i_MinInd] != std::numeric_limits<int>::max()
				&& ia_Dist[i_MinInd] + i2p_2DMap[i_MinInd][i_Ct2] < ia_Dist[i_Ct2]){
				    ia_Dist[i_Ct2] = ia_Dist[i_MinInd] + i2p_2DMap[i_MinInd][i_Ct2];
            }
		}
		std::cout<< "\n";
		fn_ShowSol(ia_Dist, i_Size);
	}
}

int main(){
    int i_Size = 6;
    int** i2p_2DMap =new int*[i_Size];
    for(int i_Ct=0; i_Ct< i_Size ; i_Ct++){
        i2p_2DMap[i_Ct] =new int[i_Size];
        std::fill(i2p_2DMap[i_Ct],
                  i2p_2DMap[i_Ct]+ i_Size , 0);
    }

    i2p_2DMap[0][1] = 2;
    i2p_2DMap[0][2] = 5;

    i2p_2DMap[1][3] = 6;
    i2p_2DMap[1][4] = 10;

    i2p_2DMap[2][3] = 9;
    i2p_2DMap[2][4] = 8;

    i2p_2DMap[3][5] = 4;

    i2p_2DMap[4][5] = 3;



    fn_Dijkstra(i2p_2DMap, 0,  i_Size);

    for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
        delete [] i2p_2DMap[i_Ct];
    }
    delete [] i2p_2DMap;

    return 0;
}



