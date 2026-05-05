# DQ Robotics Interface for CoppeliaSim V-REP

This package provides the legacy `dqrobotics.interfaces.vrep` Python bindings as a standalone extension module.
The bindings were split out from the main DQ Robotics Python package and are intended only for projects that still rely on the deprecated V-REP remote API workflow.

## Status

- Legacy package for the old V-REP interface.
- Install it only if you need `dqrobotics.interfaces.vrep`.
- For newer CoppeliaSim integrations, prefer the maintained interfaces in the main DQ Robotics ecosystem.

## Maintainers

- Original DQ Robotics interface: DQ Robotics Developers
- Standalone package port: Quentin Lin

## Installation

Install the base DQ Robotics package first, then install this package:

```bash
pip install dqrobotics
pip install dqrobotics-interface-coppeliasim-vrep
```

If you are building from a local checkout, make sure the submodules are present:

```bash
git submodule update --init --recursive
pip install .
```

This package builds a native extension, so a working C++ toolchain, CMake, and Eigen3 are required when installing from source.

## Quick Start

1. Open CoppeliaSim and create a scene with a dummy named `dummy`.
2. Start the legacy remote API service used by your scene.
3. Run the following Python script:

```python
from dqrobotics.interfaces.vrep import DQ_VrepInterface

VREP_IP = "127.0.0.1"
VREP_PORT = 19997

vrep_interface = DQ_VrepInterface()
connected = vrep_interface.connect(VREP_IP, VREP_PORT, 10, 10)
assert connected, "Failed to connect to V-REP"

pose = vrep_interface.get_object_pose("dummy")
print(pose)

vrep_interface.set_object_pose("dummy", pose)
vrep_interface.disconnect_all()
```

## Troubleshooting

- If `dqrobotics` is installed after this package, the extension may fail to import correctly in some environments. Reinstall this package after installing or upgrading `dqrobotics`.
- If the build fails from a source checkout, confirm that the git submodules were initialized and that CMake can find `Eigen3`.

## Development Notes

- Source repository: this package
- Runtime import path: `dqrobotics.interfaces.vrep`
- Package name: `dqrobotics-interface-coppeliasim-vrep`
