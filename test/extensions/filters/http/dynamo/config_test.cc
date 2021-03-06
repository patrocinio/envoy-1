#include "envoy/extensions/filters/http/dynamo/v3alpha/dynamo.pb.h"
#include "envoy/extensions/filters/http/dynamo/v3alpha/dynamo.pb.validate.h"

#include "extensions/filters/http/dynamo/config.h"

#include "test/mocks/server/mocks.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::_;

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace Dynamo {
namespace {

TEST(DynamoFilterConfigTest, DynamoFilter) {
  NiceMock<Server::Configuration::MockFactoryContext> context;
  DynamoFilterConfig factory;
  envoy::extensions::filters::http::dynamo::v3alpha::Dynamo proto_config;
  Http::FilterFactoryCb cb = factory.createFilterFactoryFromProto(proto_config, "stats", context);
  Http::MockFilterChainFactoryCallbacks filter_callback;
  EXPECT_CALL(filter_callback, addStreamFilter(_));
  cb(filter_callback);
}

} // namespace
} // namespace Dynamo
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
