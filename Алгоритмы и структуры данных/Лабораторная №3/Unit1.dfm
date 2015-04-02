object Form1: TForm1
  Left = 192
  Top = 124
  Width = 792
  Height = 511
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
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 281
    Height = 145
    TabOrder = 0
    object Label1: TLabel
      Left = 96
      Top = 8
      Width = 89
      Height = 13
      Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1091#1079#1083#1072
    end
    object Label2: TLabel
      Left = 16
      Top = 48
      Width = 119
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1091#1090#1077#1081' '#1091#1079#1083#1072':'
    end
    object Label3: TLabel
      Left = 8
      Top = 80
      Width = 130
      Height = 13
      Caption = #1057' '#1082#1072#1082#1080#1084#1080' '#1091#1079#1083#1072#1084#1080' '#1089#1074#1103#1079#1072#1085':'
    end
    object Edit1: TEdit
      Left = 144
      Top = 72
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Button1: TButton
      Left = 96
      Top = 104
      Width = 89
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      TabOrder = 1
      OnClick = Button1Click
    end
    object CSpinEdit1: TCSpinEdit
      Left = 144
      Top = 40
      Width = 121
      Height = 22
      TabOrder = 2
    end
  end
  object StringGrid1: TStringGrid
    Left = 312
    Top = 16
    Width = 369
    Height = 273
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 1
  end
end
