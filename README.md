# FARGO3D Setup: `DVSI_gas_2D_hg4x5_res100`

This repository contains a **single FARGO3D setup** called `DVSI_gas_2D_gauss_hg4x5_res100`.  
It is meant to be used together with the main [FARGO3D code](https://github.com/FARGO3D/fargo3d) (Benítez-Llambay & Masset, 2016, FARGO3D: A New GPU-Oriented MHD Code, ApJS, 223, 11.).

The setup lives in:

`DVSI_gas_2D_gauss_hg4x5_res100/`

and provides input and custom source files needed to run this particular model.

---

## Repository Contents

Inside `DVSI_gas_2D_gauss_hg4x5_res100/` you will find:

* `boundaries.txt`
  Text file describing the boundary conditions for the run.

* `condinit.c`
  C file that defines the initial conditions for the simulation and reads values from `initial.csv`.

* `DVSI_gas_2D_gauss_hg4x5_res100.bound.0`
  Boundary configuration file used by FARGO3D for this setup.

* `DVSI_gas_2D_gauss_hg4x5_res100.opt`
  Options file (e.g. code compilation/runtime options for this setup).

* `DVSI_gas_2D_gauss_hg4x5_res100.par`
  Main parameter file for the run (grid, physics, runtime parameters, etc.).

* `substep1_y.c`, `substep1_z.c`
  Modified FARGO3D source files, with added flags for background acceleration and no background pressure gradient.

---

## Requirements

* A working copy of the **FARGO3D** codebase.
* A C compiler and any dependencies required by FARGO3D (see the [FARGO3D documentation](https://fargo3d.github.io/documentation/)).
* Ability to compile FARGO3D from source.

---

## How to Use This Setup with FARGO3D

1. **Clone / download this repository**

   ```bash
   git clone <this-repo-url>
   cd <this-repo-name>
   ```

2. **Copy the setup folder into your FARGO3D tree**

   Assuming your FARGO3D source tree is in `~/fargo3d` and has a `setups/` directory:

   ```bash
   cp -r DVSI_gas_2D_gauss_hg4x5_res100 ~/fargo3d/setups/
   ```

3. **Recompile FARGO3D**

   Follow the standard FARGO3D build instructions (see [FARGO3D documentation](https://fargo3d.github.io/documentation/)).

4. **Run FARGO3D with this setup**

   ```text
   make SETUP=DVSI_gas_2D_gauss_hg4x5_res100
   ./fargo3d setups/VSI_gas_2D_gauss_hg4x5_res100/VSI_gas_2D_gauss_hg4x5_res100.par
   ```

---

## Customization Notes

* To **change initial conditions**, edit:

  * `condinit.c`
  * `initial.csv`

* To **adjust boundary conditions or parameters**, edit:

  * `boundaries.txt`
  * `DVSI_gas_2D_gauss_hg4x5_res100.bound.0`
  * `DVSI_gas_2D_gauss_hg4x5_res100.par`
  * `DVSI_gas_2D_gauss_hg4x5_res100.opt`

* To **modify the custom numerical routines**, edit:

  * `substep1_y.c`
  * `substep1_z.c`

---

## Disclaimer

* Consider keeping a separate FARGO3D clone or backing up the original file.

---

## Contact

Author: Jip Matthijsse

Email: j.p.matthijsse@tudelft.nl

Github: JipMatt

---

```

