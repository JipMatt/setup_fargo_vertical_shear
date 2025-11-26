#include "fargo3d.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float randm() {return ((float)rand()/RAND_MAX);}

void CondInit() {
  int id_gas = 0;
  int feedback = YES;
  //We first create the gaseous fluid and store it in the array Fluids
  Fluids[id_gas] = CreateFluid("gas",GAS);

  //We now select the fluid
  SelectFluid(id_gas);
  //and fill its fields
  int i,j,k;
  float AMP;
  real *rho  = Density->field_cpu;
  real *cs   = Energy->field_cpu;
  real *vx   = Vx->field_cpu;
  real *vy   = Vy->field_cpu;
  real *vz   = Vz->field_cpu;
  k = NGHZ;
  AMP = 0.00001;
  srand(CPU_Rank);
  for (k=0; k<Nz+2*NGHZ; k++) {
    for (j=0; j<Ny+2*NGHY; j++) {
      for (i=0; i<Nx+2*NGHX; i++) {
        cs[l]  = 1.0;
        rho[l] = exp(-0.5*(Zmed(k)*Zmed(k)));
        vx[l]  = 0.5*exp(-0.5*(Zmed(k)*Zmed(k))) - SHEARPARAM*OMEGAFRAME*OMEGAFRAME*Ymed(j) + AMP*(2*randm()-1.0);
        vy[l]  = 0 + AMP*(2*randm()-1.0);
        vz[l]  = 0 + AMP*(2*randm()-1.0);
      }
    }
  }
}
