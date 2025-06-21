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
#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
namespace py = pybind11;

#include <dqrobotics/DQ.h>
#include <dqrobotics/interfaces/vrep/DQ_SerialVrepRobot.h>
#include <dqrobotics/interfaces/vrep/DQ_VrepInterface.h>
#include <dqrobotics/interfaces/vrep/DQ_VrepInterfaceMapElement.h>
#include <dqrobotics/interfaces/vrep/DQ_VrepRobot.h>

//dqrobotics/interfaces/vrep
void init_DQ_SerialVrepRobot_py(py::module& m);
void init_DQ_VrepInterface_py(py::module& m);
void init_DQ_VrepRobot_py(py::module& m);
