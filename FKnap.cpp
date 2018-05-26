#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  float *fract;
  vector<int> isort;

  fract=(float *)malloc(sizeof(float)*values.size());
  for(int i=0;i<values.size();i++)
  {fract[i]= (float)values[i]/weights[i]; }
  for(int i=0;i<values.size();i++)
  {isort.push_back(i);}

  for(int k=0;k<values.size();k++)
  { for(int l=k+1;l<values.size();l++)
    {if(fract[k]>fract[l])
      {
        //int x1=fract[k],x2=fract[l];
        isort[k]=l;
        isort[l]=k;
      }
    }
  }

  int boost=capacity;int decflag=(int)values.size();
  while(boost>0)
  {if(weights[isort[decflag]]<boost)
    {//std::cout<<"Utilized "<<values[isort[decflag]] <<"from" <<weights[isort[decflag]];
      value+=values[isort[decflag]];
    boost-=weights[isort[decflag]];
    decflag--;}
    else
    { //std::cout<<"Utilized "<<boost*fract[isort[decflag]]<<"from" <<boost;
      value+=boost*fract[isort[decflag]];
      boost=0;
      break;
      return value;
    }

  }

}

int main() {
  int n;
  int capacity;
  std::cout<<"Enter elements and capacity\n";
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cout<<"\nEnter value of "<<i<<"\t";
    std::cin >> values[i] >> weights[i];

  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}