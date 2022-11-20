# https://visualtk.com
import tkinter as tk
from tkinter import ttk
import tkinter.font as tkFont
import ctypes
import sys

class App:

#    UNITS     = ['kmh', 'mph']
#    BAD_SPEED = '4294967295'
#
    __DATA_CONVERTER = {
         'bool'               : ctypes.c_bool,
         'unsigned char'      : ctypes.c_ubyte,
         'short'              : ctypes.c_short,
         'unsigned short'     : ctypes.c_ushort,
         'int'                : ctypes.c_int,
         'unsigned int'       : ctypes.c_uint,
         'long'               : ctypes.c_long,
         'unsigned long'      : ctypes.c_ulong,
         'long long'          : ctypes.c_longlong,
         'unsigned long long' : ctypes.c_ulonglong,
         'float'              : ctypes.c_float,
         'double'             : ctypes.c_double,
         'long double'        : ctypes.c_longdouble,
         'char'               : ctypes.c_char,
         'char *'             : ctypes.c_char_p,
         'char*'              : ctypes.c_char_p,
         'void *'             : ctypes.c_void_p,
         'void'               : None,
         'void*'              : ctypes.c_void_p,
         'ERROR'              : 'The type "{}" does not exists'
    }

    __C_FUNC_RTN = 'rtn_type'
    __C_FUNC_ARGS = 'arg_type'

    __C_FUNCTIONS = {
        'GearUp': {
            __C_FUNC_RTN: 'unsigned char',
            __C_FUNC_ARGS: ['void']
        },
        'GearDown':{
            __C_FUNC_RTN: 'unsigned char',
            __C_FUNC_ARGS: ['void']
        },
        'GetGear':{
            __C_FUNC_RTN: 'unsigned char',
            __C_FUNC_ARGS: ['void']
        },
        'GearType':{
            __C_FUNC_RTN: 'void',
            __C_FUNC_ARGS: ['bool']
        },
        'SpeedUp':{
            __C_FUNC_RTN: 'unsigned short',
            __C_FUNC_ARGS: ['bool']
        },
        'SpeedDown': {
            __C_FUNC_RTN: 'unsigned short',
            __C_FUNC_ARGS: ['void']
        },
    }

    def __get_c_type(self, my_type):
        """
            :description:     Uses the dictionary "__DATA_CONVERTER" to
                              convert the C types  (like char*, long, ...)
                              into the types of the ctype library (like
                              ctypes.c_char_p, ctypes.c_long, ...)
            :param my_type:   C Type to be converted to ctype
            :return:          ctypes OR string with an error message
        """
        my_type = str(my_type).lower()
        return self.__DATA_CONVERTER[my_type] if my_type in self.__DATA_CONVERTER.keys() else self.__DATA_CONVERTER['ERROR'].format(my_type)

    def __load_dll(self, path):
        try:
            if sys.version_info.minor < 8:
                self.Lib = ctypes.CDLL(path)
            else:
                self.Lib = ctypes.CDLL(path, winmode=0)
        except OSError:
            raise OSError(f'Cannot load the dll from "{path}"')


    def __call_c_function(self, function_name, *argv):
        """
            :description:           Call any C function (with or without
                                    arguments) using python. The C function
                                    called must be defined on __C_FUNCTIONS
            :param function_name:   Name of the C function: must be defined
                                    on __C_FUNCTIONS and on the C library
                                    (libediabas.dll) created with the source
                                    code present on apiEdiabas.c
            :param argv:            List of the arguments to be passed on the
                                    function
            :return:                Return of the C function as a **STRING**
        """
        result = None

        # -- FUNCTION --
        try:
            rtn_type        = self.__C_FUNCTIONS[function_name][self.__C_FUNC_RTN]
            arg_types       = self.__C_FUNCTIONS[function_name][self.__C_FUNC_ARGS]
            cast_arg_types  = list()
            cast_arg_values = list()
        except KeyError:
            error = f'Function "{function_name}" does not have one of the following: '+\
                    f'["{self.__C_FUNC_RTN}", "{self.__C_FUNC_ARGS}"] OR the function'+\
                    f'"{function_name}" do not exist on the python database.'
            raise KeyError(error)
        try:
            my_function = self.Lib[function_name]
        except AttributeError:
            error = f'The function "{function_name}" does not exist on the dll'
            raise AttributeError (error)

        # -- ARGUMENTS --
        for i in range(0, len(arg_types)):
            arg_type = arg_types[i]
            # convert the argument TYPE to C variable
            arg_cast = self.__get_c_type(arg_type)
            cast_arg_types.append(arg_cast)
            # convert the argument VALUE to C variable
            try:
                arg_val = argv[i]
                # encode utf-8 is a must for str, otherwise typeError is raised
                if ctypes.c_char_p == arg_cast:
                    cast_arg_values.append( arg_cast(arg_val.encode(self.__ENCODING_GLOBAL)) )
                else:
                    cast_arg_values.append( arg_cast(arg_val))
            except:
                # in case of no parameter were given (arg_type = void)
                continue
        # setup C function to be called: setting up the return/variables type
        ## arguments types
        if [None] != cast_arg_types:
            my_function.argtypes  = cast_arg_types

        ## -- RETURN --
        rtn_type = self.__get_c_type(rtn_type)
        my_function.restype =  rtn_type
        # -- CALL FUNCION --
        result = my_function(*cast_arg_values)
        # -- CLEAN RETURN --
        if ctypes.c_char_p == rtn_type:
            try:
                result = result.decode('utf-8')
            except UnicodeDecodeError:
                try:
                    result = result.decode('windows-1252')
                except UnicodeDecodeError:
                    raise UnicodeDecodeError('Cannot decode.')

        result = str(result).strip()
        return result


    def __init__(self):
        self.__load_dll('DriveGame.dll')
        self.root = tk.Tk()
        self.IsAutomatic = tk.BooleanVar()
        self.create_interface(self.root)

    def create_interface(self, root):
        #setting title
        root.title("Drive Game ... Really?...Is it?")
        #setting window size
        width=500
        height=350
        screenwidth = root.winfo_screenwidth()
        screenheight = root.winfo_screenheight()
        alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth - width) / 2, (screenheight - height) / 2)
        root.geometry(alignstr)
        root.resizable(width=False, height=False)
        ft = tkFont.Font(family='Times',size=10)

        #---------------------------- Gear Elements - Starts ----------------------------#
        ################################### Gear Label ###################################
        self.GLabel_Gear=tk.Label(root)
        self.GLabel_Gear["font"] = ft
        self.GLabel_Gear["fg"] = "#333333"
        self.GLabel_Gear["justify"] = "center"
        self.GLabel_Gear["text"] = "Current Gear"
        self.GLabel_Gear["relief"] = "ridge"
        self.GLabel_Gear.place(x=200,y=70,width=90,height=35)

        ################################# Gear Up Button #################################
        self.GButton_GearUp=tk.Button(root)
        self.GButton_GearUp["bg"] = "#f0f0f0"
        self.GButton_GearUp["font"] = ft
        self.GButton_GearUp["fg"] = "#000000"
        self.GButton_GearUp["justify"] = "center"
        self.GButton_GearUp["text"] = "Gear Up"
        self.GButton_GearUp.place(x=70,y=70,width=90,height=35)
        self.GButton_GearUp["command"] = self.GButton_GearUp_command

        ################################ Gear Down Button ################################
        self.GButton_GearDown=tk.Button(root)
        self.GButton_GearDown["bg"] = "#f0f0f0"
        self.GButton_GearDown["font"] = ft
        self.GButton_GearDown["fg"] = "#000000"
        self.GButton_GearDown["justify"] = "center"
        self.GButton_GearDown["text"] = "Gear Down"
        self.GButton_GearDown.place(x=70,y=120,width=90,height=35)
        self.GButton_GearDown["command"] = self.GButton_GearDown_command

        ############################### Gear Message Box #################################   
        self.GMessage_Gear=tk.Message(root)
        ftMessageGear = tkFont.Font(family='Times',size=14)
        self.GMessage_Gear["font"] = ftMessageGear
        self.GMessage_Gear["fg"] = "#333333"
        self.GMessage_Gear["justify"] = "left"
        self.GMessage_Gear["relief"] = "ridge"
        self.GMessage_Gear["text"] = "0"
        self.GMessage_Gear.place(x=200,y=120,width=90,height=35)
        
        ################################### Gear Type ####################################
        self.GCheckBox_GearType=tk.Checkbutton(root)
        self.GCheckBox_GearType["font"] = ft
        self.GCheckBox_GearType["fg"] = "#333333"
        self.GCheckBox_GearType["justify"] = "center"
        self.GCheckBox_GearType["text"] = "GearType"
        self.GCheckBox_GearType.place(x=330,y=120,width=90,height=35)
        self.GCheckBox_GearType["relief"] = "ridge"
        self.GCheckBox_GearType["offvalue"] = "0"
        self.GCheckBox_GearType["onvalue"] = "1"
        self.GCheckBox_GearType["command"] = self.GCheckBox_GearType_command
        self.GCheckBox_GearType["variable"] = self.IsAutomatic

        ############################### Gear Type Message ################################
        self.GMessage_GearType=tk.Message(root)
        ftMessageGearType = tkFont.Font(family='Times',size=14)
        self.GMessage_GearType["font"] = ftMessageGearType
        self.GMessage_GearType["fg"] = "#333333"
        self.GMessage_GearType["justify"] = "left"
        self.GMessage_GearType["relief"] = "ridge"
        self.GMessage_GearType["text"] = "M..."
        self.GMessage_GearType.place(x=330,y=70,width=90,height=35)

        #----------------------------- Gear Elements - Ends -----------------------------#

        #---------------------------- Speed Elements - Starts ---------------------------#
        ################################## Speed Label ###################################
        self.GLabel_Speed=tk.Label(root)
        self.GLabel_Speed["font"] = ft
        self.GLabel_Speed["fg"] = "#333333"
        self.GLabel_Speed["justify"] = "center"
        self.GLabel_Speed["text"] = "Current Speed"
        self.GLabel_Speed["relief"] = "ridge"
        self.GLabel_Speed.place(x=200,y=200,width=90,height=35)

        ################################ Speed Up Button #################################
        self.GButton_SpeedUp=tk.Button(root)
        self.GButton_SpeedUp["bg"] = "#f0f0f0"
        self.GButton_SpeedUp["font"] = ft
        self.GButton_SpeedUp["fg"] = "#000000"
        self.GButton_SpeedUp["justify"] = "center"
        self.GButton_SpeedUp["text"] = "Accelarate"
        self.GButton_SpeedUp.place(x=70,y=200,width=90,height=35)
        self.GButton_SpeedUp["command"] = self.GButton_SpeedUp_command

        ############################### Speed Down Button ################################
        self.GButton_SpeedDown=tk.Button(root)
        self.GButton_SpeedDown["bg"] = "#f0f0f0"
        self.GButton_SpeedDown["font"] = ft
        self.GButton_SpeedDown["fg"] = "#000000"
        self.GButton_SpeedDown["justify"] = "center"
        self.GButton_SpeedDown["text"] = "Break"
        self.GButton_SpeedDown.place(x=70,y=250,width=90,height=35)
        self.GButton_SpeedDown["command"] = self.GButton_SpeedDown_command

        ################################ Speed Edit Box ##################################
        self.GLineEdit_Speed=tk.Entry(root)
        self.GLineEdit_Speed["borderwidth"] = "1px"
        self.GLineEdit_Speed["font"] = ft
        self.GLineEdit_Speed["fg"] = "#333333"
        self.GLineEdit_Speed["justify"] = "center"
        self.GLineEdit_Speed["text"] = "Entry"

        ############################## Speed Message Box #################################   
        self.GMessage_Speed=tk.Message(root)
        ftMessage = tkFont.Font(family='Times',size=14)
        self.GMessage_Speed["font"] = ftMessage
        self.GMessage_Speed["fg"] = "#333333"
        self.GMessage_Speed["justify"] = "left"
        self.GMessage_Speed["relief"] = "ridge"
        self.GMessage_Speed["text"] = "0"
        self.GMessage_Speed.place(x=200,y=250,width=90,height=35)

    def GButton_GearUp_command(self):
        CurrentGear = self.__call_c_function('GearUp', None)
        self.GMessage_Gear["text"] = str(CurrentGear)

    def GButton_GearDown_command(self):
        CurrentGear = self.__call_c_function('GearDown', None)
        self.GMessage_Gear["text"] = str(CurrentGear)

    def GCheckBox_GearType_command(self):
        self.__call_c_function('GearType', bool(self.IsAutomatic.get()))
        if True == self.IsAutomatic.get():
            self.GMessage_GearType["text"] = "A..."
        else:
            self.GMessage_GearType["text"] = "M..."

    def GButton_SpeedUp_command(self):
        CurrentSpeed = self.__call_c_function('SpeedUp', None)
        self.GMessage_Speed["text"] = str(CurrentSpeed)
        CurrentGear = self.__call_c_function('GetGear', None)
        self.GMessage_Gear["text"] = str(CurrentGear)

    def GButton_SpeedDown_command(self):
        CurrentSpeed = self.__call_c_function('SpeedDown', None)
        self.GMessage_Speed["text"] = str(CurrentSpeed)
        CurrentGear = self.__call_c_function('GetGear', None)
        self.GMessage_Gear["text"] = str(CurrentGear)

    def start_interface(self):
        self.root.mainloop()

if __name__ == "__main__":
    x = App()
    x.start_interface()
