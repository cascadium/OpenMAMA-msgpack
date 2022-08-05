set /p VERSION=<%GITHUB_WORKSPACE%\VERSION
set OPENMAMA_INSTALL_DIR=%GITHUB_WORKSPACE%\openmama-omnm.%VCVER%.%PLATFORM%
set BUILD_DIR=%GITHUB_WORKSPACE%\build

choco install --no-progress -y unzip gow wget cmake || goto error
vcpkg install libevent:%PLATFORM%-windows apr:%PLATFORM%-windows apr-util:%PLATFORM%-windows msgpack:%PLATFORM%%-windows || goto error

mkdir %BUILD_DIR% || goto error
cd %BUILD_DIR% || goto error

set PATH=%BUILD_DIR%\src\RelWithDebInfo;%BUILD_DIR%\_deps\openmamaomnm-build\src\RelWithDebInfo;%BUILD_DIR%\_deps\openmama-build\common\c_cpp\src\c\RelWithDebInfo;%BUILD_DIR%\_deps\openmama-build\mama\c_cpp\src\c\RelWithDebInfo;C:\Program Files (x86)\Gow\bin;C:\vcpkg\installed\%PLATFORM%-windows\bin;%OPENMAMA_INSTALL_DIR%\bin;%PATH%

cmake -G "%GENERATOR%" %EXTRA_ARGS% -DCMAKE_TOOLCHAIN_FILE=c:/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=%OPENMAMA_INSTALL_DIR% -DGTEST_ROOT=C:/vcpkg/installed/%PLATFORM%-windows/ -DMAMA_ROOT=C:/vcpkg/installed/%PLATFORM%-windows/ -DAPR_ROOT=C:/vcpkg/installed/%PLATFORM%-windows/ -DAPRUTIL_ROOT=C:/vcpkg/installed/%PLATFORM%-windows/ .. || goto error
cmake --build . --config RelWithDebInfo --target install || goto error
ctest . -C RelWithDebInfo  -E MsgFieldVectorBoolTests.GetVectorBoolNullField --timeout 120 --output-on-failure || goto error

7z a openmama-omnm.%VCVER%.%PLATFORM%.zip "%OPENMAMA_INSTALL_DIR%" || goto error

goto end

:error
echo Failed with error #%errorlevel%.

:end
exit /b %errorlevel%
