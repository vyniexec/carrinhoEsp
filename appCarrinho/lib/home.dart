// ignore_for_file: avoid_print

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class Carrinho extends StatefulWidget {
  const Carrinho({super.key});

  @override
  State<Carrinho> createState() => _CarrinhoState();
}

class _CarrinhoState extends State<Carrinho> {
  bool pressionado1 = false;
  bool pressionado2 = false;
  bool pressionado3 = false;
  bool pressionado4 = false;

  directionFront(String server) async {
    while (pressionado1) {
      String url = '$server/front';
      await http.get(Uri.parse(url));
    }
  }
  directionFrontOff(String server) async {
    String url = '$server/frontOff';
    await http.get(Uri.parse(url));
  }

  directionBack(String server) async {
    while (pressionado2) {
      String url = '$server/back';
      await http.get(Uri.parse(url));
    }
  }
  directionBackOff(String server) async {
    String url = '$server/backOff';
    await http.get(Uri.parse(url));
  }

  directionLeft(String server) async {
    while(pressionado3){
      String url = '$server/left';
      await http.get(Uri.parse(url));
    }
  }
  directionLeftOff(String server) async {
    String url = '$server/leftOff';
    await http.get(Uri.parse(url));
  }

  directionRight(String server) async {
    while(pressionado4){
      String url = '$server/right';
      await http.get(Uri.parse(url));
    }
  }
  directionRightOff(String server) async {
    String url = '$server/rightOff';
    await http.get(Uri.parse(url));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('Controle Remoto Carrinho'),
          backgroundColor: Colors.blueGrey[800],
        ),
        backgroundColor: Colors.blueGrey[900],
        body: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            GestureDetector(
              onTapDown: (details) {
                setState(() {
                  pressionado1 = true;
                });
                if (pressionado1 == true) {
                  directionFront("http://192.168.1.100");
                }
              },
              onTapCancel: () {
                setState(() {
                  pressionado1 = false;
                });
                if (pressionado1 == false) {
                  directionFrontOff("http://192.168.1.100");
                }
              },
              child: ElevatedButton(
                onPressed: () {},
                child: const Text('Botão 1'),
              ),
            ),
            GestureDetector(
              onTapDown: (details) {
                setState(() {
                  pressionado2 = true;
                });
                if (pressionado2 == true) {
                  directionBack("http://192.168.1.100");
                }
              },
              onTapCancel: () {
                setState(() {
                  pressionado2 = false;
                });
                if (pressionado2 == false) {
                  directionBackOff("http://192.168.1.100");
                }
              },
              child: ElevatedButton(
                onPressed: () {},
                child: const Text('Botão 2'),
              ),
            ),
            GestureDetector(
              onTapDown: (details) {
                setState(() {
                  pressionado3 = true;
                });
                if (pressionado3 == true) {
                  directionLeft("http://192.168.1.100");
                }
              },
              onTapCancel: () {
                setState(() {
                  pressionado3 = false;
                });
                if (pressionado3 == false) {
                  directionLeftOff("http://192.168.1.100");
                }
              },
              child: ElevatedButton(
                onPressed: () {},
                child: const Text('Botão 3'),
              ),
            ),
            GestureDetector(
              onTapDown: (details) {
                setState(() {
                  pressionado4 = true;
                });
                if (pressionado4 == true) {
                  directionRight("http://192.168.1.100");
                }
              },
              onTapCancel: () {
                setState(() {
                  pressionado4 = false;
                });
                if (pressionado4 == false) {
                  directionRightOff("http://192.168.1.100");
                }
              },
              child: ElevatedButton(
                onPressed: () {},
                child: const Text('Botão 4'),
              ),
            ),
          ],
        ));
  }
}
