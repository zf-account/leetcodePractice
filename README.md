# build

## linux
```cd build```
```
cmake ..
make -j

```
## windows
```cd build```
```
cmake -G "MinGW Makefiles" ..
cmake --build .
```

## mac
```cd build```
```
cmake -G "Unix Makefiles" ..   
make -j$(sysctl -n hw.logicalcpu)
```