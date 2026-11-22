import base64,zlib
b64 = "eNq1UbENwjAQPJuADELISAwQqCiZAEUoRcZglC8oUtKGilHYDGzf2/ECvJSc7/z5P10sWFZxEV+eXDZE3xCNAcLRCebaIjMX79BIZooOXUJT9NiGtnyfMbVhpXxdkM48qWTMwll5nncPz47zO0N9UD2OlCNG7eMGtWXbgYeTBtGp24POv6lIHftH7coK+nTv8Iy7G6RUekkd4jx53PUGLiCixk/lf97/j/qGKsmZ6zS9RtRZxr8cQmdTCRhLEy3x9QMknh0R"
data = zlib.decompress(base64.b64decode(b64))
open("dump.bin","wb").write(data)
