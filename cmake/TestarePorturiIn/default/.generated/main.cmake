# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(TestarePorturiIn_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(TestarePorturiIn_default_default_XC8_FILE_TYPE_assemble)
add_library(TestarePorturiIn_default_default_XC8_assemble OBJECT ${TestarePorturiIn_default_default_XC8_FILE_TYPE_assemble})
    TestarePorturiIn_default_default_XC8_assemble_rule(TestarePorturiIn_default_default_XC8_assemble)
    list(APPEND TestarePorturiIn_default_library_list "$<TARGET_OBJECTS:TestarePorturiIn_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(TestarePorturiIn_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(TestarePorturiIn_default_default_XC8_assemblePreprocess OBJECT ${TestarePorturiIn_default_default_XC8_FILE_TYPE_assemblePreprocess})
    TestarePorturiIn_default_default_XC8_assemblePreprocess_rule(TestarePorturiIn_default_default_XC8_assemblePreprocess)
    list(APPEND TestarePorturiIn_default_library_list "$<TARGET_OBJECTS:TestarePorturiIn_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(TestarePorturiIn_default_default_XC8_FILE_TYPE_compile)
add_library(TestarePorturiIn_default_default_XC8_compile OBJECT ${TestarePorturiIn_default_default_XC8_FILE_TYPE_compile})
    TestarePorturiIn_default_default_XC8_compile_rule(TestarePorturiIn_default_default_XC8_compile)
    list(APPEND TestarePorturiIn_default_library_list "$<TARGET_OBJECTS:TestarePorturiIn_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(TestarePorturiIn_default_image_YyjakDkb ${TestarePorturiIn_default_library_list})

set_target_properties(TestarePorturiIn_default_image_YyjakDkb PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TestarePorturiIn_default_output_dir})
set_target_properties(TestarePorturiIn_default_image_YyjakDkb PROPERTIES OUTPUT_NAME "default")
set_target_properties(TestarePorturiIn_default_image_YyjakDkb PROPERTIES SUFFIX ".elf")

target_link_libraries(TestarePorturiIn_default_image_YyjakDkb PRIVATE ${TestarePorturiIn_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
TestarePorturiIn_default_link_rule(TestarePorturiIn_default_image_YyjakDkb)



