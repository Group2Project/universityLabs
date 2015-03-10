object Form1: TForm1
  Left = 192
  Top = 124
  Width = 382
  Height = 182
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 32
    Width = 54
    Height = 13
    Caption = #1057#1090#1086#1088#1086#1085#1072' 1:'
  end
  object Label3: TLabel
    Left = 48
    Top = 56
    Width = 54
    Height = 13
    Caption = #1057#1090#1086#1088#1086#1085#1072' 2:'
  end
  object Label5: TLabel
    Left = 8
    Top = 112
    Width = 54
    Height = 13
    Caption = #1057#1090#1086#1088#1086#1085#1072' 3:'
  end
  object Label4: TLabel
    Left = 72
    Top = 80
    Width = 28
    Height = 13
    Caption = #1059#1075#1086#1083':'
  end
  object Label2: TLabel
    Left = 192
    Top = 112
    Width = 50
    Height = 13
    Caption = #1055#1083#1086#1097#1072#1076#1100':'
  end
  object Side1: TEdit
    Left = 104
    Top = 24
    Width = 145
    Height = 21
    TabOrder = 0
  end
  object Side2: TEdit
    Left = 104
    Top = 48
    Width = 145
    Height = 21
    TabOrder = 1
  end
  object Angle: TEdit
    Left = 104
    Top = 72
    Width = 145
    Height = 21
    TabOrder = 2
  end
  object Side3: TEdit
    Left = 64
    Top = 104
    Width = 89
    Height = 21
    TabOrder = 3
  end
  object Calculate: TButton
    Left = 256
    Top = 24
    Width = 81
    Height = 25
    Caption = #1055#1086#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 4
    OnClick = CalculateClick
  end
  object Reset: TButton
    Left = 256
    Top = 48
    Width = 81
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 5
    OnClick = ResetClick
  end
  object Exit: TButton
    Left = 256
    Top = 72
    Width = 81
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 6
    OnClick = ExitClick
  end
  object Area: TEdit
    Left = 248
    Top = 104
    Width = 89
    Height = 21
    TabOrder = 7
  end
end
