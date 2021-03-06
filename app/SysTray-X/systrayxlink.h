#ifndef SYSTRAYXLINK_H
#define SYSTRAYXLINK_H


/*
 *	Local includes
 */
#include "preferences.h"


/*
 *	Qt includes
 */
#include <QObject>
#include <QJsonDocument>


/*
 *	Predefines
 */
class QFile;
class QTimer;
class QThread;


/**
 * @brief The SysTrayXLinkReader class. Reader thread.
 */
class SysTrayXLinkReader : public QObject
{
    Q_OBJECT

    public:

        /**
         * @brief Reader. Constructor, destructor.
         */
        SysTrayXLinkReader();
        ~SysTrayXLinkReader();

        /**
         * @brief stopThread. Stop the thread.
         */
        void    stopThread();

    public slots:

        /**
         * @brief startThread. Start the thread.
         */
        void	startThread();

        /**
         * @brief slotWorker. The worker thread started by a "timer".
         */
        void	slotWorker();

    signals:

        /**
         * @brief signalReceivedMessage. Signal the received message.
         *
         *  @param message  The received message.
         */
        void    signalReceivedMessage( QByteArray message );

        /**
         * @brief signalAddOnShutdown. Signal to shutdown the app.
         */
        void    signalAddOnShutdown();

    private:

        /**
         * @brief m_timer. Worker timer.
         */
        QTimer* m_timer;

        /**
         * @brief m_doWork. Status of the worker thread.
         */
        bool	m_doWork;
};


/**
 * @brief The SysTrayXLink class. Handles the communications link.
 */
class SysTrayXLink : public QObject
{
    Q_OBJECT

    public:

        /**
         * @brief SysTrayXLink. Constructor, destructor.
         */
        SysTrayXLink( Preferences* pref );
        ~SysTrayXLink();

        /**
         * @brief linkWrite. Write a message to the link.
         *
         *  @param message  Message to be written.
         */
        void    linkWrite( const QByteArray& message );

        /**
         * @brief sendPreferences. Send the preferences to the add-on.
         */
        void    sendPreferences();

        /**
         * @brief sendWindowNormal. Send the window normal command.
         */
        void sendWindowNormal();

        /**
         * @brief sendWindowMinimize. Send the window minimize command.
         */
        void    sendWindowMinimize();

    private:

        /**
         * @brief MessageDecode. Decode a JSON message.
         *
         * @param message   The message.
         */
        void    DecodeMessage( const QByteArray& message );

        /**
         * @brief DecodePreferences. Decode a JSON preference object.
         *
         * @param pref  The JSON preferences.
         */
        void    DecodePreferences( const QJsonObject& pref );

        /**
         * @brief EncodePreferences. Encode the preferences into a JSON document.
         *
         *  @param pref     The preferences.
         */
        void    EncodePreferences( const Preferences& pref );

    signals:

        /**
         * @brief signalTitle. Signal to title the app.
         */
        void    signalTitle( QString title );

        /**
         * @brief signalAddOnShutdown. Signal to shutdown the app.
         */
        void    signalAddOnShutdown();

        /**
         * @brief signalWindowState. Signal a change in the window state.
         */
        void    signalWindowState( QString state );

        /**
         * @brief signalUnreadMail. Signal numder of unread mails.
         *
         * @param unreadMail    The number of unread mails.
         */
        void    signalUnreadMail( int unread_mail );

    public slots:

        /**
         * @brief slotDebugChange. Handle a change in debug state.
         */
        void    slotDebugChange();

        /**
         * @brief slotHideOnMinimizeChange. Handle a change in hide on minimize state.
         */
        void    slotHideOnMinimizeChange();

        /**
         * @brief slotStartMinimizeChange. Handle a change in start minimized state.
         */
        void    slotStartMinimizedChange();

        /**
         * @brief slotIconTypeChange. Slot for handling icon type change signals.
         */
        void    slotIconTypeChange();

        /**
         * @brief slotIconDataChange. Slot for handling icon data change signals.
         */
        void    slotIconDataChange();

        /**
         * @brief slotWindowNormal. Slot for handling window normal signals.
         */
        void    slotWindowNormal();

        /**
         * @brief slotWindowMinimize. Slot for handling window minimize signals.
         */
        void    slotWindowMinimize();

     private slots:

        /**
         * @brief slotLinkRead. Read the link.
         */
        void    slotLinkRead( QByteArray message );

        /**
         * @brief slotAddOnShutdown. Handle sahutdown signal from reader thread.
         */
        void    slotAddOnShutdown();

    private:

        /**
         * @brief m_reader_thread. Pointer to the reader thread.
         */
        QThread*    m_reader_thread;

        /**
         * @brief m_pref. Pointer to the preferences storage.
         */
        Preferences*    m_pref;

        /**
         * @brief m_pref_json_doc. Temporary storage for the preferences to be send.
         */
        QJsonDocument   m_pref_json_doc;
};

#endif // SYSTRAYXLINK_H
