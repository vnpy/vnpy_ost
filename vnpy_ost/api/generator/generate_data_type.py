""""""

TYPE_CPP2PY = {
    "int": "int",
    "char": "char",
    "uint16_t": "uint16_t",
    "uint32_t": "uint32_t",
    "int32_t": "int32_t",
    "int64_t": "int64_t",
    "double": "double",
    "short": "short",
    "long": "long long"
}


class DataTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str):
        """Constructor"""
        self.filename = filename
        self.prefix = prefix

    def run(self):
        """主函数"""
        if self.prefix == "md":
            self.f_cpp = open(self.filename, "r", encoding='UTF-8')
        else:
            self.f_cpp = open(self.filename, "r")
        self.f_define = open(f"{self.prefix}_constant.py", "w")
        self.f_typedef = open(f"{self.prefix}_typedef.py", "w")

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        self.f_define.close()
        self.f_typedef.close()

        print(f"{self.prefix}DataType生成完毕")

    def process_line(self, line: str):
        """处理每行"""
        line = line.replace("\n", "")

        if line.startswith("#define"):
            self.process_define(line)
        elif line.startswith("typedef"):
            self.process_typedef(line)

    def process_define(self, line: str):
        """处理常量定义"""
        words = line.split(" ")
        words = [word for word in words if word]
        if len(words) < 3:
            return

        name = words[1]
        value = words[2]

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)

    def process_typedef(self, line: str):
        """处理类型定义"""
        line = line.split(";")[0]
        words = line.split(" ")
        words = [word for word in words if word != " "]

        name = words[-1]
        typedef = TYPE_CPP2PY[words[1]]

        if typedef == "char":
            if "[" in name:
                typedef = "string"
                name = name[:name.index("[")]

        new_line = f"{name} = \"{typedef}\"\n"
        self.f_typedef.write(new_line)


if __name__ == "__main__":
    md_generator = DataTypeGenerator("../include/ost/SecurityDntL2MDUserApiDataType.h", "md")
    md_generator.run()

    td_generator = DataTypeGenerator("../include/ost/UTApiDataType.h", "td")
    td_generator.run()
