package Globant.example2.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

@Service
public class AppService{

  private String from = "jfelipefg17@gmail.com";//dirección de correo que hace el envío.
  private String to = "juanpiflorezg@gmail.com";//dirección de correo que recibe el mail.


  @Autowired
  private JavaMailSender mailSender;
  public void sendEmail(String from, String to) {



    SimpleMailMessage message = new SimpleMailMessage();
    message.setFrom(from);
    message.setTo(to);
    message.setSubject("Asunto del correo");
    message.setText("Este es un correo automático!");
    mailSender.send(message); //método Send(envio), propio de Java Mail Sender.

  }
}