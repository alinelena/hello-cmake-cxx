if (WITH_MYMATH)
  add_library(utils mymath.cxx)
  if (${BUILD_SHARED_LIBS})
    set_target_properties(
		  utils PROPERTIES VERSION ${Hello_VERSION}
		  SOVERSION ${Hello_VERSION_MAJOR})
  endif()
  list(APPEND Hello_LIBS utils)
  set(Hello_LIBS "${Hello_LIBS}" PARENT_SCOPE)
  install(TARGETS utils
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
   )
endif()
