#include <iostream>
#include <sstream>
#include <vector>
#include "trimesh.h" 
#include <string>
#include <Eigen/Dense>
#include <math>
#include <algorithm>
using namespace std;
using namespace Eigen;
// modify
int main(int argc, char *argv[])
{// commite new 1127
// new modity hehe
  std::cout<< argc << std::endl;  
  std::cout<< argv[1] << std::endl;
  std::string filename = "../data/head_cleaned_align_normal.obj";
  trimesh mesh1;
  mesh1.load(filename);
  std::string save_path = "trimesh.obj";
  mesh1.save(save_path);
  Eigen::MatrixXd vert_normal(mesh1.vertices.size(),3);
  std::cout << "vert_normal计算开始" << endl;
  mesh1.cal_vert_normal(mesh1.vertices, mesh1.faces);
  mesh1.cal_face_normal(mesh1.vertices, mesh1.faces);
  std::cout << "vert_normal计算完毕" << endl;

  /*
  // 网格细分例子
  std::vector<std::vector<double>> vert_subdiv;
  std::vector<std::vector<int>> face_subdiv;
  tie(vert_subdiv, face_subdiv) = mesh1.subdiv_mid();
  trimesh mesh_subdiv;
  mesh_subdiv.vertices = vert_subdiv;
  mesh_subdiv.faces    = face_subdiv;
  std::string save_path_subdiv = "trimesh_subdiv.obj";
  mesh_subdiv.save(save_path_subdiv);
  */

  //mesh1.cal_vert_normal();
  //mesh1.cal_face_normal();
  //mesh1.find_edge_verts();
  return 0;

}

