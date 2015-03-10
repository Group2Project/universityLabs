object Form1: TForm1
  Left = 192
  Top = 124
  Width = 301
  Height = 188
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
    Left = 56
    Top = 24
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object Label2: TLabel
    Left = 56
    Top = 56
    Width = 8
    Height = 13
    Caption = 'N'
  end
  object Label3: TLabel
    Left = 56
    Top = 120
    Width = 3
    Height = 13
  end
  object X: TEdit
    Left = 72
    Top = 16
    Width = 89
    Height = 21
    TabOrder = 0
  end
  object N: TEdit
    Left = 72
    Top = 48
    Width = 89
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 64
    Top = 80
    Width = 105
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
end
