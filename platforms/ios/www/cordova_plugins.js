cordova.define('cordova/plugin_list', function(require, exports, module) {
module.exports = [
    {
        "id": "bridging.bridging",
        "file": "plugins/bridging/www/bridging.js",
        "pluginId": "bridging",
        "clobbers": [
            "bridging"
        ]
    }
];
module.exports.metadata = 
// TOP OF METADATA
{
    "cordova-plugin-whitelist": "1.3.2",
    "bridging": "3.0.0"
};
// BOTTOM OF METADATA
});