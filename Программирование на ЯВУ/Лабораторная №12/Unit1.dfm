object Form1: TForm1
  Left = 240
  Top = 214
  Width = 870
  Height = 640
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 305
    Height = 233
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 0
    object Label1: TLabel
      Left = 120
      Top = 56
      Width = 40
      Height = 13
      Caption = #1060#1080#1083#1100#1084':'
    end
    object Label2: TLabel
      Left = 96
      Top = 80
      Width = 62
      Height = 13
      Caption = #1050#1080#1085#1086#1089#1090#1091#1076#1080#1103':'
    end
    object Label3: TLabel
      Left = 104
      Top = 104
      Width = 54
      Height = 13
      Caption = #1056#1077#1078#1080#1089#1089#1077#1088':'
    end
    object Label4: TLabel
      Left = 64
      Top = 128
      Width = 91
      Height = 13
      Caption = #1044#1072#1090#1072' 1-'#1075#1086' '#1087#1086#1082#1072#1079#1072':'
    end
    object Label5: TLabel
      Left = 24
      Top = 152
      Width = 130
      Height = 13
      Caption = #1044#1072#1090#1072' '#1087#1086#1089#1083#1077#1076#1085#1077#1075#1086' '#1087#1086#1082#1072#1079#1072':'
    end
    object Label6: TLabel
      Left = 104
      Top = 32
      Width = 56
      Height = 13
      Caption = #1050#1080#1085#1086#1090#1077#1072#1090#1088':'
    end
    object Edit1: TEdit
      Left = 168
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 168
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 168
      Top = 72
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 168
      Top = 96
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Edit5: TEdit
      Left = 168
      Top = 120
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object Edit6: TEdit
      Left = 168
      Top = 144
      Width = 121
      Height = 21
      TabOrder = 5
    end
    object Button1: TButton
      Left = 112
      Top = 184
      Width = 89
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      TabOrder = 6
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 336
    Top = 16
    Width = 353
    Height = 481
    Caption = #1042#1099#1074#1086#1076
    TabOrder = 1
    object Button2: TButton
      Left = 136
      Top = 432
      Width = 75
      Height = 25
      Caption = #1042#1099#1074#1086#1076
      TabOrder = 0
      OnClick = Button2Click
    end
    object Memo1: TMemo
      Left = 32
      Top = 32
      Width = 289
      Height = 385
      Lines.Strings = (
        'Memo1')
      TabOrder = 1
    end
  end
  object Button3: TButton
    Left = 96
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 2
    OnClick = Button3Click
  end
end
