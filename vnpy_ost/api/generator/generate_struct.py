""""""
import importlib


class StructGenerator:
    """Struct生成器"""

    def __init__(self, filename: str, prefix: str):
        """Constructor"""
        self.filename = filename
        self.prefix = prefix
        self.typedefs = {}

        self.load_constant()

    def load_constant(self):
        """"""
        module_name = f"{self.prefix}_typedef"
        module = importlib.import_module(module_name)

        for name in dir(module):
            if "__" not in name:
                self.typedefs[name] = getattr(module, name)

    def run(self):
        """运行生成"""
        if self.prefix == "md":
            self.f_cpp = open(self.filename, "r", encoding='UTF-8')
        else:
            self.f_cpp = open(self.filename, "r")
        self.f_struct = open(f"{self.prefix}_struct.py", "w")

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        self.f_struct.close()

        print(f"{self.prefix}Struct生成成功")

    def process_line(self, line: str):
        """处理每行"""
        line = line.replace("\n", "")

        if line.startswith("struct"):
            self.process_declare(line)
        elif line.startswith("};"):
            self.process_end(line)
        elif line.startswith("{") or "public:" in line or "()" in line or "memset" in line or "}"in line or line.startswith("//") or "// U" in line or "//买卖盘" in line or "//委托笔数揭示" in line:
            self.process_start(line)
        elif "\t" in line and "///" not in line:
            self.process_member(line)

    def process_declare(self, line: str):
        """处理声明"""
        words = line.split(" ")
        name = words[1]
        end = "{"

        new_line = f"{name} = {end}\n"
        self.f_struct.write(new_line)

    def process_start(self, line: str):
        """处理开始"""
        pass

    def process_end(self, line: str):
        """处理结束"""
        new_line = "}\n\n"
        self.f_struct.write(new_line)

    def process_member(self, line: str):
        """处理成员"""
        line_ = line.rsplit(";")[0]
        words_ = line_.replace(" ", "\t")
        words = words_.split("\t")
        words = [word for word in words if word != "\t"]

        py_type = self.typedefs.get(words[1], "enum")
        if words[1] == "EntryInfoList":
            py_type = "dict"
        name = words[-1]
        if "[" in name:
            py_type = "string"
            name = name.split("[")[0]

        new_line = f"    \"{name}\": \"{py_type}\",\n"
        self.f_struct.write(new_line)


if __name__ == "__main__":
    md_generator = StructGenerator("../include/ost/SecurityDntL2MDUserApiDataStruct.h", "md")
    md_generator.run()

    td_generator = StructGenerator("../include/ost/UTApiStruct.h", "td")
    td_generator.run()