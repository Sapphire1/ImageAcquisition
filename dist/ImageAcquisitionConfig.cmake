# This file is used when other components needs to use something provided by this DCL. 
# Provide any include paths and lib directories. Use /home/lzmuda/DCL/ImageAcquisition/dist
# to point to 'dist' directory of current DCL, it'll be substituted during installation. 

# directory containing header files
SET(ImageAcquisition_INCLUDE_DIR /home/lzmuda/DCL/ImageAcquisition/dist/include)
INCLUDE_DIRECTORIES(${ImageAcquisition_INCLUDE_DIR})

# directory containing libraries
SET(ImageAcquisition_LIB_DIR /home/lzmuda/DCL/ImageAcquisition/dist/lib)
LINK_DIRECTORIES(${ImageAcquisition_LIB_DIR})

# list of libraries to link against when using features of ImageAcquisition
# add all additional libraries built by this dcl (NOT components)
# SET(ImageAcquisition_LIBS lib_1 lib_2)
# SET(ADDITIONAL_LIB_DIRS /home/lzmuda/DCL/ImageAcquisition/dist/lib ${ADDITIONAL_LIB_DIRS})
