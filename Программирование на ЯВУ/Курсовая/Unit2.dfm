object Form2: TForm2
  Left = 267
  Top = 133
  Width = 811
  Height = 824
  Caption = #1050#1091#1088#1089#1086#1074#1072#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 144
    Top = 0
    Width = 649
    Height = 761
    Caption = #1057#1080#1089#1090#1077#1084#1072' '#1076#1086#1088#1086#1075
    TabOrder = 0
    object Image1: TImage
      Left = 8
      Top = 16
      Width = 633
      Height = 737
      OnClick = Image1Click
      OnMouseMove = Image1MouseMove
    end
  end
  object select_in_mode: TRadioGroup
    Left = 16
    Top = 16
    Width = 121
    Height = 73
    Caption = #1042#1074#1086#1076
    ItemIndex = 0
    Items.Strings = (
      #1043#1086#1088#1086#1076
      #1044#1086#1088#1086#1075#1072)
    TabOrder = 1
    OnClick = select_in_modeClick
  end
  object gb_am_city_connect: TGroupBox
    Left = 16
    Top = 96
    Width = 121
    Height = 49
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1086#1088#1086#1075
    TabOrder = 2
    object CSpinEdit1: TCSpinEdit
      Left = 8
      Top = 16
      Width = 97
      Height = 22
      TabOrder = 0
    end
  end
  object MainMenu1: TMainMenu
    Left = 760
    Top = 8
    object N6: TMenuItem
      Caption = #1056#1077#1078#1080#1084' '#1074#1074#1086#1076#1072
      OnClick = N6Click
    end
    object N1: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N2: TMenuItem
        Caption = #1054' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1080
      end
      object N3: TMenuItem
        Caption = #1056#1091#1082#1086#1074#1086#1076#1089#1090#1074#1086
      end
      object N4: TMenuItem
        Caption = #1056#1072#1079#1088#1072#1073#1086#1090#1095#1080#1082
        OnClick = N4Click
      end
    end
    object N5: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N5Click
    end
  end
end
