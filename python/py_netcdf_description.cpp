/*
* (C) Copyright 2023 NOAA/NWS/NCEP/EMC
*
* This software is licensed under the terms of the Apache Licence Version 2.0
* which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <pybind11/pybind11.h>

#include <string>

#include "bufr/encoders/netcdf/Description.h"
#include "bufr/encoders/netcdf/Encoder.h"


namespace py = pybind11;
namespace nc = netCDF;

using bufr::DataContainer;
using bufr::encoders::netcdf::Encoder;
using bufr::encoders::netcdf::Description;

void setupNetcdfDescription(py::module& m)
{
  py::class_<Description>(m, "Description")
   .def(py::init<const std::string&>())
   .def("add_variable", &Description::py_addVariable,
        py::arg("name"),
        py::arg("source"),
        py::arg("units"),
        py::arg("longName") = "", "");
}
