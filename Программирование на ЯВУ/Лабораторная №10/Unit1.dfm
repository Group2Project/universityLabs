object Form1: TForm1
  Left = 3
  Top = 129
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 434
  ClientWidth = 1249
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
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 1249
    Height = 433
    Transparent = True
  end
  object Image2: TImage
    Left = 9
    Top = 208
    Width = 313
    Height = 121
    Transparent = True
  end
  object Button1: TButton
    Left = 8
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 648
    Top = 8
  end
end
