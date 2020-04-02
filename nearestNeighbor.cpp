#include <iostream> 
#include <cmath>
using namespace std; 

bool areEqual(int arr1[], int arr2[]){
  for(int i = 0; i < 2; ++i){
    if (arr1[i] != arr2[i])
      return false;
  }
  return true;
}

double pythagoreanDistance(int point1[], int point2[]){
  // A^2 + B^2 = C^2
  double A = fabs(point1[0] - point2[0]);
  double B = fabs(point1[1] - point2[1]);
  double C = (A*A) + (B*B);
  return sqrt(C);
}

int nearestNeighborRoute(int points[][2], int size, int lastVisited[2] )
{
  int ctr = 0;
  int checker[2] = {INT_MAX,INT_MAX};
  do {
    // Initialize best distance to max int (should be less than this)
    double currBestDistance = INT_MAX;
    int currBestLoc; 

    // Loop through points given ignoring points marked as visited (vector of {INT_MAX, INT_MAX})
    for(int i = 0; i < size; ++i){
      if (!areEqual(points[i], checker)){
        // get the pythagoreanDistance between lastVisited and the current point in loop 
        double distance = pythagoreanDistance(lastVisited, points[i]);
        // if distance is less than currBestDistance then update currBestDistance and Location
        if (distance < currBestDistance){
          currBestDistance = distance;
          currBestLoc = i;
        }
      }
    }

    // lastVisited is set to the currBestLocation
    lastVisited[0] = points[currBestLoc][0];
    lastVisited[1] = points[currBestLoc][1];
    cout << ctr << ": " << lastVisited[0] << ", " << lastVisited[1] << "\n";

    // currBestLocation is marked as Visited
    points[currBestLoc][0] = INT_MAX;
    points[currBestLoc][1] = INT_MAX;

    ++ctr;
  } while (ctr < size);
    
  return 0;
}

int main(){
  int points[5][2] {{3,2}, {0,1}, {0,5}, {4,4}, {2,3}};
  int startingLocation[2] = {0,0};

  cout << "The fastest route starting at {" << startingLocation[0] << ", " << startingLocation[1] << "} according to Nearest Neighbor is: \n";
  nearestNeighborRoute(points, 5, startingLocation);     
}