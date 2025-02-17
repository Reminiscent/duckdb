//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/parser/expression/list.hpp"

namespace duckdb {

void ParsedExpression::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "class", expression_class);
	serializer.WriteProperty(101, "type", type);
	serializer.WriteProperty(102, "alias", alias);
}

unique_ptr<ParsedExpression> ParsedExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto expression_class = deserializer.ReadProperty<ExpressionClass>(100, "class");
	auto type = deserializer.ReadProperty<ExpressionType>(101, "type");
	auto alias = deserializer.ReadProperty<string>(102, "alias");
	deserializer.Set<ExpressionType>(type);
	unique_ptr<ParsedExpression> result;
	switch (expression_class) {
	case ExpressionClass::BETWEEN:
		result = BetweenExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CASE:
		result = CaseExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CAST:
		result = CastExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COLLATE:
		result = CollateExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COLUMN_REF:
		result = ColumnRefExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COMPARISON:
		result = ComparisonExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CONJUNCTION:
		result = ConjunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CONSTANT:
		result = ConstantExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::DEFAULT:
		result = DefaultExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::FUNCTION:
		result = FunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::LAMBDA:
		result = LambdaExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::OPERATOR:
		result = OperatorExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::PARAMETER:
		result = ParameterExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::POSITIONAL_REFERENCE:
		result = PositionalReferenceExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::STAR:
		result = StarExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::SUBQUERY:
		result = SubqueryExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::WINDOW:
		result = WindowExpression::FormatDeserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of ParsedExpression!");
	}
	deserializer.Unset<ExpressionType>();
	result->alias = std::move(alias);
	return result;
}

void BetweenExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "input", *input);
	serializer.WriteProperty(201, "lower", *lower);
	serializer.WriteProperty(202, "upper", *upper);
}

unique_ptr<ParsedExpression> BetweenExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<BetweenExpression>(new BetweenExpression());
	deserializer.ReadProperty(200, "input", result->input);
	deserializer.ReadProperty(201, "lower", result->lower);
	deserializer.ReadProperty(202, "upper", result->upper);
	return std::move(result);
}

void CaseExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "case_checks", case_checks);
	serializer.WriteProperty(201, "else_expr", *else_expr);
}

unique_ptr<ParsedExpression> CaseExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CaseExpression>(new CaseExpression());
	deserializer.ReadProperty(200, "case_checks", result->case_checks);
	deserializer.ReadProperty(201, "else_expr", result->else_expr);
	return std::move(result);
}

void CastExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "child", *child);
	serializer.WriteProperty(201, "cast_type", cast_type);
	serializer.WriteProperty(202, "try_cast", try_cast);
}

unique_ptr<ParsedExpression> CastExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CastExpression>(new CastExpression());
	deserializer.ReadProperty(200, "child", result->child);
	deserializer.ReadProperty(201, "cast_type", result->cast_type);
	deserializer.ReadProperty(202, "try_cast", result->try_cast);
	return std::move(result);
}

void CollateExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "child", *child);
	serializer.WriteProperty(201, "collation", collation);
}

unique_ptr<ParsedExpression> CollateExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CollateExpression>(new CollateExpression());
	deserializer.ReadProperty(200, "child", result->child);
	deserializer.ReadProperty(201, "collation", result->collation);
	return std::move(result);
}

void ColumnRefExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "column_names", column_names);
}

unique_ptr<ParsedExpression> ColumnRefExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ColumnRefExpression>(new ColumnRefExpression());
	deserializer.ReadProperty(200, "column_names", result->column_names);
	return std::move(result);
}

void ComparisonExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "left", *left);
	serializer.WriteProperty(201, "right", *right);
}

unique_ptr<ParsedExpression> ComparisonExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ComparisonExpression>(new ComparisonExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty(200, "left", result->left);
	deserializer.ReadProperty(201, "right", result->right);
	return std::move(result);
}

void ConjunctionExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "children", children);
}

unique_ptr<ParsedExpression> ConjunctionExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConjunctionExpression>(new ConjunctionExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty(200, "children", result->children);
	return std::move(result);
}

void ConstantExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "value", value);
}

unique_ptr<ParsedExpression> ConstantExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConstantExpression>(new ConstantExpression());
	deserializer.ReadProperty(200, "value", result->value);
	return std::move(result);
}

void DefaultExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
}

unique_ptr<ParsedExpression> DefaultExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<DefaultExpression>(new DefaultExpression());
	return std::move(result);
}

void FunctionExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "function_name", function_name);
	serializer.WriteProperty(201, "schema", schema);
	serializer.WriteProperty(202, "children", children);
	serializer.WriteOptionalProperty(203, "filter", filter);
	serializer.WriteProperty(204, "order_bys", (ResultModifier &)*order_bys);
	serializer.WriteProperty(205, "distinct", distinct);
	serializer.WriteProperty(206, "is_operator", is_operator);
	serializer.WriteProperty(207, "export_state", export_state);
	serializer.WriteProperty(208, "catalog", catalog);
}

unique_ptr<ParsedExpression> FunctionExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<FunctionExpression>(new FunctionExpression());
	deserializer.ReadProperty(200, "function_name", result->function_name);
	deserializer.ReadProperty(201, "schema", result->schema);
	deserializer.ReadProperty(202, "children", result->children);
	deserializer.ReadOptionalProperty(203, "filter", result->filter);
	auto order_bys = deserializer.ReadProperty<unique_ptr<ResultModifier>>(204, "order_bys");
	result->order_bys = unique_ptr_cast<ResultModifier, OrderModifier>(std::move(order_bys));
	deserializer.ReadProperty(205, "distinct", result->distinct);
	deserializer.ReadProperty(206, "is_operator", result->is_operator);
	deserializer.ReadProperty(207, "export_state", result->export_state);
	deserializer.ReadProperty(208, "catalog", result->catalog);
	return std::move(result);
}

void LambdaExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "lhs", *lhs);
	serializer.WriteProperty(201, "expr", *expr);
}

unique_ptr<ParsedExpression> LambdaExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LambdaExpression>(new LambdaExpression());
	deserializer.ReadProperty(200, "lhs", result->lhs);
	deserializer.ReadProperty(201, "expr", result->expr);
	return std::move(result);
}

void OperatorExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "children", children);
}

unique_ptr<ParsedExpression> OperatorExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<OperatorExpression>(new OperatorExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty(200, "children", result->children);
	return std::move(result);
}

void ParameterExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "identifier", identifier);
}

unique_ptr<ParsedExpression> ParameterExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ParameterExpression>(new ParameterExpression());
	deserializer.ReadProperty(200, "identifier", result->identifier);
	return std::move(result);
}

void PositionalReferenceExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "index", index);
}

unique_ptr<ParsedExpression> PositionalReferenceExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<PositionalReferenceExpression>(new PositionalReferenceExpression());
	deserializer.ReadProperty(200, "index", result->index);
	return std::move(result);
}

void StarExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "relation_name", relation_name);
	serializer.WriteProperty(201, "exclude_list", exclude_list);
	serializer.WriteProperty(202, "replace_list", replace_list);
	serializer.WriteProperty(203, "columns", columns);
	serializer.WriteOptionalProperty(204, "expr", expr);
}

unique_ptr<ParsedExpression> StarExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<StarExpression>(new StarExpression());
	deserializer.ReadProperty(200, "relation_name", result->relation_name);
	deserializer.ReadProperty(201, "exclude_list", result->exclude_list);
	deserializer.ReadProperty(202, "replace_list", result->replace_list);
	deserializer.ReadProperty(203, "columns", result->columns);
	deserializer.ReadOptionalProperty(204, "expr", result->expr);
	return std::move(result);
}

void SubqueryExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "subquery_type", subquery_type);
	serializer.WriteProperty(201, "subquery", subquery);
	serializer.WriteOptionalProperty(202, "child", child);
	serializer.WriteProperty(203, "comparison_type", comparison_type);
}

unique_ptr<ParsedExpression> SubqueryExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<SubqueryExpression>(new SubqueryExpression());
	deserializer.ReadProperty(200, "subquery_type", result->subquery_type);
	deserializer.ReadProperty(201, "subquery", result->subquery);
	deserializer.ReadOptionalProperty(202, "child", result->child);
	deserializer.ReadProperty(203, "comparison_type", result->comparison_type);
	return std::move(result);
}

void WindowExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "function_name", function_name);
	serializer.WriteProperty(201, "schema", schema);
	serializer.WriteProperty(202, "catalog", catalog);
	serializer.WriteProperty(203, "children", children);
	serializer.WriteProperty(204, "partitions", partitions);
	serializer.WriteProperty(205, "orders", orders);
	serializer.WriteProperty(206, "start", start);
	serializer.WriteProperty(207, "end", end);
	serializer.WriteOptionalProperty(208, "start_expr", start_expr);
	serializer.WriteOptionalProperty(209, "end_expr", end_expr);
	serializer.WriteOptionalProperty(210, "offset_expr", offset_expr);
	serializer.WriteOptionalProperty(211, "default_expr", default_expr);
	serializer.WriteProperty(212, "ignore_nulls", ignore_nulls);
	serializer.WriteOptionalProperty(213, "filter_expr", filter_expr);
}

unique_ptr<ParsedExpression> WindowExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<WindowExpression>(new WindowExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty(200, "function_name", result->function_name);
	deserializer.ReadProperty(201, "schema", result->schema);
	deserializer.ReadProperty(202, "catalog", result->catalog);
	deserializer.ReadProperty(203, "children", result->children);
	deserializer.ReadProperty(204, "partitions", result->partitions);
	deserializer.ReadProperty(205, "orders", result->orders);
	deserializer.ReadProperty(206, "start", result->start);
	deserializer.ReadProperty(207, "end", result->end);
	deserializer.ReadOptionalProperty(208, "start_expr", result->start_expr);
	deserializer.ReadOptionalProperty(209, "end_expr", result->end_expr);
	deserializer.ReadOptionalProperty(210, "offset_expr", result->offset_expr);
	deserializer.ReadOptionalProperty(211, "default_expr", result->default_expr);
	deserializer.ReadProperty(212, "ignore_nulls", result->ignore_nulls);
	deserializer.ReadOptionalProperty(213, "filter_expr", result->filter_expr);
	return std::move(result);
}

} // namespace duckdb
