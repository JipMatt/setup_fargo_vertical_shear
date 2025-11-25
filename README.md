# FARGO3D Setup: `DVSI_gas_2d_hg4x5_res100`

This repository contains a **single FARGO3D setup** called `DVSI_gas_2d_hg4x5_res100`.  
It is meant to be used together with the main FARGO3D code (Benítez-Llambay & Masset, 2016, FARGO3D: A New GPU-Oriented MHD Code, ApJS, 223, 11.).

The setup lives in:

DVSI_gas_2d_hg4x5_res100/


and provides input and custom source files needed to run this particular model.

---

## Repository Contents

Inside `DVSI_gas_2d_hg4x5_res100/` you will find:

* `boundaries.txt`
  Text file describing the boundary conditions for the run.

* `condinit.c`
  C file that defines the initial conditions for the simulation and reads values from `initial.csv`.

* `DVSI_gas_2d_hg4x5_res100.bound.0`
  Boundary configuration file used by FARGO3D for this setup.

* `DVSI_gas_2d_hg4x5_res100.opt`
  Options file (e.g. code compilation/runtime options for this setup).

* `DVSI_gas_2d_hg4x5_res100.par`
  Main parameter file for the run (grid, physics, runtime parameters, etc.).

* `global.h` ⚠️
  **This file does *not* belong in the setups folder in a working FARGO3D tree.**
  It is a customized replacement for FARGO3D’s `src/global.h` and must be copied there
  (see instructions below).

* `initial.csv`
  CSV file with additional initial data (densities, velocities, and accelerations used by `condinit.c`).

* `lowtasks.c`,`substep1_y.c`, `substep1_z.c`
  Modified FARGO3D source files, with added flags for background acceleration, static field setup, and no background pressurgrandient.

---

## Requirements

* A working copy of the **FARGO3D** codebase.
* A C compiler and any dependencies required by FARGO3D (see the FARGO3D documentation).
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
   cp -r DVSI_gas_2d_hg4x5_res100 ~/fargo3d/setups/
   ```

3. **Replace FARGO3D’s `global.h`**

   ```bash
   cd ~/fargo3d
   cp src/global.h src/global.h.backup   # optional but recommended
   cp setups/DVSI_gas_2d_hg4x5_res100/global.h src/global.h
   ```

4. **Recompile FARGO3D**

   Follow the standard FARGO3D build instructions (see [documentation](https://fargo3d.github.io/documentation/)).

5. **Run FARGO3D with this setup**

   Use the usual FARGO3D command for selecting a setup, using the setup name:

   ```text
   DVSI_gas_2d_hg4x5_res100
   ```

   The exact command depends on how you normally run FARGO3D (see the FARGO3D documentation for the precise syntax).

---

## Customization Notes

* To **change initial conditions**, edit:

  * `condinit.c`
  * `initial.csv`

* To **adjust boundary conditions or parameters**, edit:

  * `boundaries.txt`
  * `DVSI_gas_2d_hg4x5_res100.bound.0`
  * `DVSI_gas_2d_hg4x5_res100.par`
  * `DVSI_gas_2d_hg4x5_res100.opt`

* To **modify the custom numerical routines**, edit:

  * `lowtasks.c`
  * `substep1_y.c`
  * `substep1_z.c`
  * `global.h` (and re-copy it to `src/global.h` if you change it)

---

## Disclaimer

* This repository only contains a **single setup** and a replacement `global.h`; it is **not** a complete hydrodynamics code.
* Use at your own risk: replacing `src/global.h` can affect other setups in the same FARGO3D tree.
  Consider keeping a separate FARGO3D clone or backing up the original file.

---


```

