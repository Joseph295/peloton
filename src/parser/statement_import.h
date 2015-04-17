#pragma once

#include "sql_statement.h"

namespace nstore {
namespace parser {

/**
 * @struct ImportStatement
 * @brief Represents "IMPORT"
 */
struct ImportStatement : SQLStatement {
	enum ImportType {
		kImportCSV,
		kImportTbl, // Hyrise file format
	};


	ImportStatement(ImportType type) :
		SQLStatement(kStmtImport),
		type(type),
		file_path(NULL),
		table_name(NULL) {};
		
	virtual ~ImportStatement() {
		delete file_path;
		delete table_name;
	}


	ImportType type;
	const char* file_path;
	const char* table_name;
};

} // End parser namespace
} // End nstore namespace
