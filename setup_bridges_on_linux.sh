#!/bin/bash
#
# The steps to install Bridges on Code.CS
#
# Official instructions: http://bridgesuncc.github.io/bridges_setup.html
# These steps can be modified to install the libraries on other sytems.
#

# Save all files in an include directory.
# Note: Uncomment the rm command if you want to delete the previous setup.
#rm -r include
mkdir include
cd include

# First download and extract the Bridges library
# - Get the download link from the bridges site under downloads menu.
#   http://bridgesuncc.github.io/
#
# Download BRIDGES
wget http://bridgesuncc.github.io/sw/bridges-cxx-3.0.1-x86_64-linux-gnu.tgz
# Extract BRIDGES
tar -xzf bridges-cxx-3.0.1-x86_64-linux-gnu.tgz
mv bridges-cxx-3.0.1-x86_64-linux-gnu bridges

# Second download and install the CURL library
#  - The CURL site has the download file for different system with instructions.
#    https://curl.haxx.se/
# 
# Download CURL
wget https://curl.haxx.se/download/curl-7.69.1.tar.gz
# Extract CURL
tar -xzf curl-7.69.1.tar.gz
# Install CURL
cd curl-7.69.1
./configure --prefix=/home/project/code/cpp/student242/include/curl
make
make install
