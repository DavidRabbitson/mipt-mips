/**
 * Unit test for Bypass module
 * @author Egor Bova
 * Copyright 2019 MIPT-MIPS team
 */

#include "../data_bypass.h"
#include "../data_bypass_interface.h"

#include <mips/mips.h>
#include <mips/mips_instr.h>
#include <catch.hpp>

class MIPS32Instr : public BaseMIPSInstr<uint32>
{
public:
	explicit MIPS32Instr( std::string_view str_opcode) : BaseMIPSInstr<uint32>( MIPSVersion::v32, str_opcode, Endian::little, 0x0000, 0xc000) { }
};

TEST_CASE( "Test test_case")
{
	DataBypass<MIPS32Instr> db( 7);
	MIPS32Instr load( "lw");
	db.trace_new_instr( load);
	CHECK( 1);
}