CMAKE_MINIMUM_REQUIRED( VERSION 3.1.2 )


get_filename_component(SOURCE_DIRECTORY_NAME ${CMAKE_SOURCE_DIR} NAME)


function(qt_compilers arg1)
    #message ( STATUS ${QT_LOCATION} )
    execute_process( COMMAND ${QT_LOCATION}/bin/uic.exe -o ${CMAKE_SOURCE_DIR}/${arg1}.ui.h ${CMAKE_SOURCE_DIR}/${arg1}.ui )
    execute_process( COMMAND ${QT_LOCATION}/bin/moc.exe -o ${CMAKE_SOURCE_DIR}/${arg1}.moc.cpp ${CMAKE_SOURCE_DIR}/${arg1}.h )
endfunction(convert_ui_to_h)


# Section for project specific settings

set( PROJ_NAME "plot_test" )

set( QT_LOCATION F:/compiled_libraries/qt_5_4 )
qt_compilers("mainwindow")


set( PROJ_LIBRARIES ${QT_LOCATION}/lib/libQt5Widgets.a ${QT_LOCATION}/lib/libQt5Core.a )
set( PROJ_INCLUDES ${QT_LOCATION}/include )
file( GLOB_RECURSE PROJ_SOURCES *.cpp )

# End of special section


set( CMAKE_CXX_FLAGS "-std=c++11" )
if ( UNIX )
    set( CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}" )
endif ( UNIX )


set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../___bin___/${SOURCE_DIRECTORY_NAME}___${CMAKE_BUILD_TYPE}/" )
project( ${PROJ_NAME} )
include_directories( ${PROJ_INCLUDES} )
add_executable( ${PROJ_NAME} ${PROJ_SOURCES} )
target_link_libraries( ${PROJ_NAME} ${PROJ_LIBRARIES} )