/**
(C) Copyright 2019-2025 DQ Robotics Developers

This file is part of DQ Robotics.

    DQ Robotics is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DQ Robotics is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with DQ Robotics.  If not, see <http://www.gnu.org/licenses/>.

Contributors:
- Murilo M. Marinho (murilomarinho@ieee.org)

- Quentin Lin (qlin1806@g.ecc.u-tokyo.ac.jp)
 - porting og vrep to standalone module
*/

#include "modules.h"


PYBIND11_MODULE(_core, m) {

  /*****************************************************
  *  Interfaces vrep Submodule
  * **************************************************/\
  init_DQ_VrepInterface_py(m);
  py::module vrep_robot_py = m.def_submodule("_robot", "A submodule of dqrobotics");
  init_DQ_VrepRobot_py(vrep_robot_py);
  init_DQ_SerialVrepRobot_py(vrep_robot_py);
}